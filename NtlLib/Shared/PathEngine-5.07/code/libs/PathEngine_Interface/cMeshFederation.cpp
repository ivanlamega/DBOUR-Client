//**********************************************************************
//
// Copyright (c) 2006
// PathEngine
// Lyon, France
//
// All Rights Reserved
//
//**********************************************************************

#include "platform_common/Header.h"
#include "interface/cMeshFederation.h"
#include "interface/cPathEngine.h"
#include "interface/cContentChunkInstance.h"
#include "interface/Singletons.h"
#include "RepresentedRegionOverlaps.h"
#include "HorizontallyOffsetFVM.h"
#include "HorizontallyOffsetAnchorsAndShapes.h"
#include "libs/Content_Processing/interface/Export.h"
#include "libs/PathEngine_Core/interface/version.h"
#include "libs/Mesh3D/interface/tMesh_3D.h"
#include "libs/Mesh3D/interface/CopyMesh3DPart.h"
#include "libs/Mesh3D/interface/ValidateMesh_Import.h"
#include "libs/Mesh3D/interface/PlaneEquation.h"
#include "libs/Mesh_Common/interface/FaceBounds.h"
#include "libs/Geometry/interface/Bounds.h"
#include "libs/ParseXML/interface/ParseToSimpleDOM.h"
#include "libs/ParseXML/interface/SimpleDOM.h"
#include "libs/ParseXML/interface/StandardXMLOutputStream.h"
#include "libs/ParseXML/interface/TokenisedXMLOutputStream.h"
#include "libs/Instrumentation/interface/Profiler.h"
#include "common/TemplateMesh/External.h"
#include "common/Containers/CollapsedVectorVector.h"
#include "iAPIObjectWrapper.h"
#include "common/interface/Assert.h"
#include "common/interface/Error.h"
#include "common/interface/Attributes.h"
#include "common/STL/string.h"
#include "common/STL/sstream.h"

class cTerrainStandinForRange : public iFaceVertexMesh
{
    cHorizontalRange _range;

public:

    cTerrainStandinForRange(const cHorizontalRange& range) :
     _range(range)
    {
    }

// interface for iFaceVertexMesh
    
    long faces() const
    {
        return 2;
    }
    long vertices() const
    {
        return 4;
    }
    long vertexIndex(long face, long vertexInFace) const
    {
        if(face == 0)
        {
            return vertexInFace;
        }
        switch(vertexInFace)
        {
        case 0:
            return 3;
        case 1:
            return 2;
        default:
            return 1;
        }
    }
    long vertexX(long vertex) const
    {
        if(vertex > 1)
        {
            return _range.maxX + 1;
        }
        return _range.minX - 1;
    }
    long vertexY(long vertex) const
    {
        if(vertex & 1)
        {
            return _range.maxY + 1;
        }
        return _range.minY - 1;
    }
    float vertexZ(long vertex) const
    {
        return 0.f;
    }
    long faceAttribute(long face, long attributeIndex) const
    {
        if(attributeIndex == PE_FaceAttribute_SectionID)
        {
            return 0; // mark all faces as sectionID == 0 (first terrain layer)
        }
        return -1;
    }
};

static void
AddRange(cHorizontalRange& addTo, const cHorizontalRange& toAdd)
{
    if(toAdd.minX < addTo.minX)
    {
        addTo.minX = toAdd.minX;
    }
    if(toAdd.minY < addTo.minY)
    {
        addTo.minY = toAdd.minY;
    }
    if(toAdd.maxX > addTo.maxX)
    {
        addTo.maxX = toAdd.maxX;
    }
    if(toAdd.maxY > addTo.maxY)
    {
        addTo.maxY = toAdd.maxY;
    }
}

static void
AdjustMeshForTileOrigin(
        tMesh_3D& mesh,
        long centreX, long centreY
        )
{
    tVertex_3D v = mesh.beginVertex();
    do
    {
        v->_x -= centreX;
        v->_y -= centreY;
    }
    while((++v).valid());
}

// the root postions for the resulting copied obstacles will need to be remapped later
static void
CopyObstacles_AddFacesIfNecessary(
        const std::vector<cObstacleInfo>& obstacles,
        const std::vector<cCollisionShape>& shapes,
        const std::vector<std::string>* ids,
        long minX, long minY, long maxX, long maxY,
        const cMesh& worldMesh,
        tMesh_3D& mesh3DResult,
        std::vector<long>& faceRemap,
        std::vector<cObstacleInfo>& copiedObstacles,
        std::vector<cCollisionShape>& copiedShapes,
        std::vector<std::string>* copiedIDs
        )
{
    tPoint rrMin(minX, minY, WORLD_RANGE);
    tPoint rrMax(maxX, maxY, WORLD_RANGE);
    assertD(obstacles.size() == shapes.size());
    long i;
    for(i = 0; i != SizeL(obstacles); ++i)
    {
        tPoint p = obstacles[i]._position.p;
        tPoint minimum, maximum;
        shapes[i].getBounds(minimum, maximum);
        minimum += p;
        maximum += p;
        if(!BoundsOverlap_Inclusive(rrMin, rrMax, minimum, maximum))
        {
            continue;
        }

      // this obstacle overlaps represented range

        cPosition pos;
        worldMesh.convertPosition(obstacles[i]._position, pos);
        long fIndex = worldMesh.get3DFaceAtPosition(pos);
        if(faceRemap[fIndex] == -1)
        {
          // face for obstacle root has not been copied yet
          // i.e. this face does not overlap the represented region
          // copy the face now so that we can root the obstacle at the same position on the copied mesh
            AddFaceToCopiedMesh3DPart(const_cast<tMesh_3D&>(worldMesh.ref3D()), fIndex, mesh3DResult, faceRemap);
        }

        // copy entries

        copiedObstacles.push_back(obstacles[i]);
        copiedShapes.push_back(shapes[i]);
        if(ids)
        {
            assertD(copiedIDs);
            copiedIDs->push_back((*ids)[i]);
        }
    }
}

// postions for the resulting copied anchors will need to be remapped later
static void
CopyAnchors(
        const std::vector<std::string>& ids,
        const std::vector<cPosition>& positions,
        const std::vector<long>& orientations,
        long minX, long minY, long maxX, long maxY,
        std::vector<std::string>& copiedIDs,
        std::vector<cPosition>& copiedPositions,
        std::vector<long>& copiedOrientations
        )
{
    tPoint rrMin(minX, minY, WORLD_RANGE);
    tPoint rrMax(maxX, maxY, WORLD_RANGE);
    assertD(ids.size() == positions.size());
    assertD(ids.size() == orientations.size());
    long i;
    for(i = 0; i != SizeL(ids); ++i)
    {
        tPoint p = tPoint(positions[i].x, positions[i].y, WORLD_RANGE);
        if(!p.insideOrOnBounds(rrMin, rrMax))
        {
            continue;
        }

      // this anchor is inside the represented range

        // copy entries

        copiedIDs.push_back(ids[i]);
        copiedPositions.push_back(positions[i]);
        copiedOrientations.push_back(orientations[i]);
    }

}

static void
AdjustAndRemapCopiedObstaclePositions(
        const cMesh& worldMesh,
        const std::vector<long>& faceRemap,
        long centreX, long centreY,
        const cMesh& targetMesh,
        std::vector<cObstacleInfo>& obstacles
        )
{
    long i;
    for(i = 0; i != SizeL(obstacles); ++i)
    {
        cPosition pos;
        worldMesh.convertPosition(obstacles[i]._position, pos);
        long fIndex = worldMesh.get3DFaceAtPosition(pos);
        long remappedFIndex = faceRemap[fIndex];
        assertD(remappedFIndex != -1);

        tPoint& p = obstacles[i]._position.p;
        long x = p.getX() - centreX;
        long y = p.getY() - centreY;
        p = tPoint(x, y, WORLD_RANGE);

        cPosition remappedPos = targetMesh.translateFrom3D(remappedFIndex, p.getX(), p.getY());
        targetMesh.convertPosition(remappedPos, obstacles[i]._position);
    }
}

static void
AdjustAndRemapCopiedAnchorPositions(
        const cMesh& worldMesh,
        const std::vector<long>& faceRemap,
        long centreX, long centreY,
        const cMesh& targetMesh,
        std::vector<cPosition>& positions
        )
{
    long i;
    for(i = 0; i != SizeL(positions); ++i)
    {
        long fIndex = worldMesh.get3DFaceAtPosition(positions[i]);
        long remappedFIndex = faceRemap[fIndex];
        assertD(remappedFIndex != -1);

        positions[i].x -= centreX;
        positions[i].y -= centreY;

        positions[i] = targetMesh.translateFrom3D(remappedFIndex, positions[i].x, positions[i].y);
    }
}

static void
RepresentedRegionRange_OneAxis(
        long start,
        long tileSize, long tilesAcross,
        long overlap,
        long testStart, long testEnd,
        long& firstOverlapped, long& lastOverlapped
        )
{
    // test range must be completely within world range
    assertD(testStart >= start);
    assertD(testEnd < start + tileSize * tilesAcross);

    long startOffset = testStart - start - overlap;
    firstOverlapped = startOffset / tileSize;
    if(firstOverlapped >= tilesAcross - 1)
    {
        firstOverlapped = tilesAcross - 1;
        lastOverlapped = firstOverlapped;
        return;
    }
    lastOverlapped = firstOverlapped;
    while(1)
    {
        if(lastOverlapped + 1 == tilesAcross)
        {
            return;
        }
        long nextRepresentedRegionStart = start + (lastOverlapped + 1) * tileSize - overlap;
        if(testEnd <= nextRepresentedRegionStart)
        {
            return;
        }
        lastOverlapped++;
    }
}

void
cMeshFederation::pushBackSubsets(const tPoint& bottomLeft, const tPoint& topRight, cCollapsedVectorVector<long>& result)
{
    long xFirst, xLast, yFirst, yLast;
    RepresentedRegionRange_OneAxis(_startX, _tileSize, _tilesInX, _overlap, bottomLeft.getX(), topRight.getX(), xFirst, xLast);
    RepresentedRegionRange_OneAxis(_startY, _tileSize, _tilesInY, _overlap, bottomLeft.getY(), topRight.getY(), yFirst, yLast);
    for(long y = yFirst; y <= yLast; ++y)
    {
        for(long x = xFirst; x <= xLast; ++x)
        {
            result.pushBackInLastSubVector(y * _tilesInX + x);
            result.pushBackInLastSubVector(-1);
        }
    }
}

void
cMeshFederation::buildSubsetsLookup(const cMesh& worldMesh, cCollapsedVectorVector<long>& result)
{
    PROFILER_CHANGES("cMeshFederation::buildSubsetsLookup");
    tFace_3D f = worldMesh.ref3D().beginFace();
    do
    {
        result.pushBackSubVector();
        tPoint bottomLeft, topRight;
        GetFaceBounds<tMesh_3D>(f, bottomLeft, topRight);
        pushBackSubsets(bottomLeft, topRight, result);
    }
    while(!(++f)->isExternal());

    for(long i = 0; i != _tiles; ++i)
    {
        long facesInTile = 0;
        for(long j = 0; j != result.size(); ++j)
        {
            for(long k = 0; k != result.subVectorSize(j); k += 2)
            {
                if(result[j][k] != i)
                {
                    continue;
                }
                result[j][k + 1] = facesInTile++;
            }
        }
    }
}

bool
cMeshFederation::isInHandledRegion_Local(long tileIndex, long x, long y) const
{
    cHorizontalRange range;
    getHandledRegion_Local(tileIndex, range);
    return x >= range.minX && x <= range.maxX && y >= range.minY && y <= range.maxY;
}

void
cMeshFederation::doSave(iXMLOutputStream& xos) const
{
    xos.openElement("federation");
    xos.addAttribute("majorRelease", MajorRelease());
    xos.addAttribute("minorRelease", MinorRelease());
    xos.addAttribute("startX", _startX);
    xos.addAttribute("startY", _startY);
    xos.addAttribute("width", _width);
    xos.addAttribute("height", _height);
    xos.addAttribute("tileSize", _tileSize);
    xos.addAttribute("overlap", _overlap);
    if(_translatesBySectionID)
    {
        xos.addAttribute("translatesBySectionID", "true");
    }
    xos.closeElement("federation");
}

void
cMeshFederation::constructorCommon()
{
    _wrapper = 0;
    _translatesBySectionID = false;
    _tilesInX = _width / _tileSize;
    if(_tilesInX * _tileSize != _width)
    {
        _tilesInX++;
    }
    _tilesInY = _height / _tileSize;
    if(_tilesInY * _tileSize != _height)
    {
        _tilesInY++;
    }
    _tiles = _tilesInX * _tilesInY;
}


cMeshFederation::cMeshFederation(
            const cHorizontalRange& worldRange,
            long tileSize, long overlap,
            cList_NoSize<cMeshFederation*>::iterator heldNode
            ) :
 _tileSize(tileSize),
 _overlap(overlap)
{
    _heldNode = heldNode;
    _startX = worldRange.minX;
    _startY = worldRange.minY;
    _width = worldRange.maxX - _startX;
    _height = worldRange.maxY - _startY;
    assertD(_width >= 0);
    assertD(_height >= 0);
    if(_width == 0)
    {
        _width++;
    }
    if(_height == 0)
    {
        _height++;
    }
    assertD(_tileSize > 0);
    constructorCommon();
    _translatesBySectionID = true;
}

cMeshFederation::cMeshFederation(
            const cMesh& worldMesh,
            long tileSize, long overlap,
            iMeshFederationTileGeneratedCallBack& tileGeneratedCallBack,
            cList_NoSize<cMeshFederation*>::iterator heldNode
            ) :
 _tileSize(tileSize),
 _overlap(overlap)
{
    PROFILER_SCOPE("cMeshFederation::cMeshFederation (from world mesh) top");
    if(worldMesh.hasOffMeshConnections())
    {
        Error("NonFatal",
            "buildMeshFederation_FromWorldMesh() called with a world mesh with off-mesh connections."
            "  These are not currently supported by the tile mesh generation process, and will not be copied through to the generated tile meshes.");
    }
    if(worldMesh.hasBaseSurfaceTypeCosts())
    {
        Error("NonFatal",
            "buildMeshFederation_FromWorldMesh() called with a world mesh with burnt-in 'surface-type traversal costs'."
            "  These are not currently supported by the tile mesh generation process, and will not be copied through to the generated tile meshes.");
    }
    
// construct the mesh federation object itself

    _heldNode = heldNode;
    tPoint bottomLeft, topRight;
    worldMesh.getRange(bottomLeft, topRight);
    _startX = bottomLeft.getX();
    _startY = bottomLeft.getY();
    _width = topRight.getX() - _startX;
    _height = topRight.getY() - _startY;
    assertD(_width > 0);
    assertD(_height > 0);
    assertD(_tileSize > 0);
    constructorCommon();

// build the tile meshes

    cCollapsedVectorVector<long> subsetsLookup;
    buildSubsetsLookup(worldMesh, subsetsLookup);

    std::vector<long> faceRemap(worldMesh.getNumberOf3DFaces());
    std::vector<cObstacleInfo> copiedBaseObstacles;
    std::vector<cCollisionShape> copiedBaseObstacleShapes;
    std::vector<cObstacleInfo> copiedNamedObstacles;
    std::vector<cCollisionShape> copiedNamedObstacleShapes;
    std::vector<std::string> copiedNamedObstacleIDs;
    std::vector<std::string> copiedAnchorIDs;
    std::vector<cPosition> copiedAnchorPositions;
    std::vector<long> copiedAnchorOrientations;

    for(long tileIndex = 0; tileIndex != size(); ++tileIndex)
    {
        PROFILER_SCOPE("cMeshFederation::cMeshFederation tile loop, copy mesh 3d part");

        iMesh* tileMesh;

        tMesh_3D mesh3D;
        CopyMesh3DPart(const_cast<tMesh_3D&>(worldMesh.ref3D()), subsetsLookup, tileIndex, mesh3D, faceRemap);
        if(mesh3D.empty())
        {
            continue;
        }

        PROFILER_CHANGES("cMeshFederation::cMeshFederation tile loop, copy obstacles and anchors");
        {
            cHorizontalRange rr;
            getRepresentedRegion_World(tileIndex, rr);

            copiedBaseObstacles.resize(0);
            copiedBaseObstacleShapes.resize(0);
            CopyObstacles_AddFacesIfNecessary(
                    worldMesh.refBaseObstacles(), worldMesh.refBaseObstacleShapes(), 0,
                    rr.minX, rr.minY, rr.maxX, rr.maxY,
                    worldMesh,
                    mesh3D, faceRemap,
                    copiedBaseObstacles, copiedBaseObstacleShapes, 0
                    );

            copiedNamedObstacles.resize(0);
            copiedNamedObstacleShapes.resize(0);
            copiedNamedObstacleIDs.resize(0);
            CopyObstacles_AddFacesIfNecessary(
                    worldMesh.refNamedObstacles(), worldMesh.refNamedObstacleShapes(), &worldMesh.refNamedObstacleIDs(),
                    rr.minX, rr.minY, rr.maxX, rr.maxY,
                    worldMesh,
                    mesh3D, faceRemap,
                    copiedNamedObstacles, copiedNamedObstacleShapes, &copiedNamedObstacleIDs
                    );

            copiedAnchorIDs.resize(0);
            copiedAnchorPositions.resize(0);
            copiedAnchorOrientations.resize(0);
            CopyAnchors(
                worldMesh.refAnchorIDs(), worldMesh.refAnchorPositions(), worldMesh.refAnchorOrientations(),
                rr.minX, rr.minY, rr.maxX, rr.maxY,
                copiedAnchorIDs, copiedAnchorPositions, copiedAnchorOrientations
                );
        }

      // generate 3d face data channels as necessary

        PROFILER_CHANGES("cMeshFederation::cMeshFederation tile loop, generate data channels");

        std::vector<long>* surfaceTypes = 0;
        std::vector<long>* sectionIDs = 0;
        std::vector<long>* userData = 0;
        for(long i = 0; i != SizeL(faceRemap); ++i)
        {
            long remappedF = faceRemap[i];
            if(remappedF == -1)
            {
                continue;
            }
            long surfaceType = worldMesh.get3DFaceAttribute(i, PE_FaceAttribute_SurfaceType);
            if(surfaceType != 0)
            {
                if(!surfaceTypes)
                {
                    surfaceTypes = new std::vector<long>(mesh3D.faces(), 0);
                }
                (*surfaceTypes)[remappedF] = surfaceType;
            }
            long sectionID = worldMesh.get3DFaceAttribute(i, PE_FaceAttribute_SectionID);
            if(sectionID != -1)
            {
                if(!sectionIDs)
                {
                    sectionIDs = new std::vector<long>(mesh3D.faces(), -1);
                }
                (*sectionIDs)[remappedF] = sectionID;
            }
            long userDataValue = worldMesh.get3DFaceAttribute(i, PE_FaceAttribute_UserData);
            if(userDataValue != 0)
            {
                if(!userData)
                {
                    userData = new std::vector<long>(mesh3D.faces(), 0);
                }
                (*userData)[remappedF] = userDataValue;
            }
        }

        PROFILER_CHANGES("cMeshFederation::cMeshFederation tile loop, adjust mesh");

        long centreX, centreY;
        getTileCentre(tileIndex, centreX, centreY);
        AdjustMeshForTileOrigin(mesh3D, centreX, centreY);

        PROFILER_CHANGES("cMeshFederation::cMeshFederation tile loop, finalise tile mesh");

        AddExternalFaces(mesh3D);
        mesh3D.consolidate(); 
        assertD(ValidateMesh_Import(mesh3D));
        CalculatePlaneEquations(mesh3D);

        PROFILER_CHANGES("cMeshFederation::cMeshFederation tile loop, constructMeshFrom3D");

        tileMesh = nSingletons::pathEngine().constructMeshFrom3D(mesh3D, surfaceTypes, sectionIDs, userData, 0);
        cMesh* tileMeshC = static_cast<cMesh*>(tileMesh);

        PROFILER_CHANGES("cMeshFederation::cMeshFederation tile loop, adjust, remap attach");

        AdjustAndRemapCopiedObstaclePositions(worldMesh, faceRemap, centreX, centreY, *tileMeshC, copiedBaseObstacles);
        AdjustAndRemapCopiedObstaclePositions(worldMesh, faceRemap, centreX, centreY, *tileMeshC, copiedNamedObstacles);
        AdjustAndRemapCopiedAnchorPositions(worldMesh, faceRemap, centreX, centreY, *tileMeshC, copiedAnchorPositions);
        tileMeshC->attachBaseObstacles(copiedBaseObstacleShapes, copiedBaseObstacles);
        tileMeshC->attachNamedObstacles(copiedNamedObstacleIDs, copiedNamedObstacleShapes, copiedNamedObstacles);
        tileMeshC->attachAnchors(copiedAnchorIDs, copiedAnchorPositions, copiedAnchorOrientations);

        PROFILER_CHANGES("cMeshFederation::cMeshFederation tile loop, construct represented region overlaps");

        cRepresentedRegionOverlaps* overlaps = new cRepresentedRegionOverlaps(subsetsLookup, tileIndex);
        tileMeshC->attachRepresentedRegionOverlaps(overlaps);

        PROFILER_CHANGES("cMeshFederation::cMeshFederation tile loop, callback");
        tileGeneratedCallBack.tileGenerated(tileIndex, tileMesh);
    }
}

cMeshFederation::cMeshFederation(
        const char* format, const char* dataBuffer, unsigned long bufferSize,
        cList_NoSize<cMeshFederation*>::iterator heldNode
        )
{
    _heldNode = heldNode;
    cSimpleDOM doc;
    ParseToSimpleDOM(format, dataBuffer, bufferSize, doc);
    assertD(doc.name() == "federation");
    _startX = doc.attributeAsLong("startX");
    _startY = doc.attributeAsLong("startY");
    _width = doc.attributeAsLong("width");
    _height = doc.attributeAsLong("height");
    _tileSize = doc.attributeAsLong("tileSize");
    _overlap = doc.attributeAsLong("overlap");
    constructorCommon();
    _translatesBySectionID = doc.attributeAsBoolWithDefault("translatesBySectionID", false);
}

cMeshFederation::~cMeshFederation()
{
    assertD(!_heldNode.valid());
}


// iMeshFederation

void 
cMeshFederation::destroy()
{
    INTERFACE_ASSERT(_heldNode.valid());
    if(_wrapper) {_wrapper->destroy_APIObjectWrapper();}
    nSingletons::pathEngine().lockHeldFederations();
    _heldNode.eraseAndSetInvalid();
    nSingletons::pathEngine().unlockHeldFederations();
    delete this;
}

void
cMeshFederation::save(const char* format, iOutputStream* outputStream) const
{
    INTERFACE_ASSERT(strcmp(format, "tok") == 0 || strcmp(format, "xml") == 0);
    if(strcmp(format, "tok") == 0)
    {
        cElementAndAttributeEnumerator enumerator;
        doSave(enumerator);
        enumerator.writeTo(*outputStream);
        cTokenisedXMLOutputStream xos(enumerator, *outputStream);
        doSave(xos);
        return;
    }
    cStandardXMLOutputStream os(*outputStream);
    doSave(os);
}

long
cMeshFederation::size() const
{
    return _tiles;
}

bool
cMeshFederation::coordinatesAreInsideRange(long x, long y) const
{
    return x >= _startX && (x - _startX) < _width && y >= _startY && (y - _startY) < _height;
}
long
cMeshFederation::tileForQuery(long queryStartX, long queryStartY) const
{
    INTERFACE_ASSERT(coordinatesAreInsideRange(queryStartX, queryStartY));
    long tileX = (queryStartX - _startX) / _tileSize;
    long tileY = (queryStartY - _startY) / _tileSize;
    return tileY * _tilesInX + tileX;
}

void
cMeshFederation::getTileCentre(long tileIndex, long& centreX, long& centreY) const
{
    assertD(tileIndex >= 0 && tileIndex < _tiles);
    long tileY = tileIndex / _tilesInX;
    long tileX = tileIndex - (tileY * _tilesInX);
    centreX = _startX + tileX * _tileSize + _tileSize / 2;
    centreY = _startY + tileY * _tileSize + _tileSize / 2;
}
void
cMeshFederation::getHandledRegion_World(long tileIndex, cHorizontalRange& result) const
{
    assertD(tileIndex >= 0 && tileIndex < _tiles);
    long tileY = tileIndex / _tilesInX;
    long tileX = tileIndex - (tileY * _tilesInX);
    result.minX = _startX + tileX * _tileSize;
    result.minY = _startY + tileY * _tileSize;
// region x and y end are last integer value in the region
    result.maxX = _startX + (tileX + 1) * _tileSize - 1;
    result.maxY = _startY + (tileY + 1) * _tileSize - 1;
}
void
cMeshFederation::getRepresentedRegion_World(long tileIndex, cHorizontalRange& result) const
{
    assertD(tileIndex >= 0 && tileIndex < _tiles);
    long tileY = tileIndex / _tilesInX;
    long tileX = tileIndex - (tileY * _tilesInX);
    result.minX = _startX + tileX * _tileSize - _overlap;
    result.minY = _startY + tileY * _tileSize - _overlap;
// region x and y end are last integer value in the region
    result.maxX = _startX + (tileX + 1) * _tileSize + _overlap - 1;
    result.maxY = _startY + (tileY + 1) * _tileSize + _overlap - 1;
// resulting overlapping region is then clipped to world bounds
    if(result.minX < _startX)
    {
        result.minX = _startX;
    }
    if(result.maxX > _startX + _width)
    {
        result.maxX = _startX + _width;
    }
    if(result.minY < _startY)
    {
        result.minY = _startY;
    }
    if(result.maxY > _startY + _height)
    {
        result.maxY = _startY + _height;
    }
}

void
cMeshFederation::getHandledRegion_Local(long tileIndex, cHorizontalRange& result) const
{
    getHandledRegion_World(tileIndex, result);
    long centreX, centreY;
    getTileCentre(tileIndex, centreX, centreY);
    result.minX -= centreX;
    result.minY -= centreY;
    result.maxX -= centreX;
    result.maxY -= centreY;
}
void
cMeshFederation::getRepresentedRegion_Local(long tileIndex, cHorizontalRange& result) const
{
    getRepresentedRegion_World(tileIndex, result);
    long centreX, centreY;
    getTileCentre(tileIndex, centreX, centreY);
    result.minX -= centreX;
    result.minY -= centreY;
    result.maxX -= centreX;
    result.maxY -= centreY;
}

cPosition
cMeshFederation::translatePosition(long fromMeshIndex, const iMesh* fromMesh, long toMeshIndex, const iMesh* toMesh, const cPosition& fromPosition) const
{
    INTERFACE_ASSERT(fromMesh);
    INTERFACE_ASSERT(toMesh);
    INTERFACE_ASSERT(fromMeshIndex >= 0 && fromMeshIndex < _tiles);
    INTERFACE_ASSERT(toMeshIndex >= 0 && toMeshIndex < _tiles);
    INTERFACE_ASSERT(fromMesh->positionIsValid(fromPosition));
//.... also check somehow that from and to meshes actually match the meshes generated at the corresponding indices in this federation

    if(toMeshIndex == fromMeshIndex)
    {
        return fromPosition;
    }
    long fromCentreX, fromCentreY;
    long toCentreX, toCentreY;
    getTileCentre(fromMeshIndex, fromCentreX, fromCentreY);
    getTileCentre(toMeshIndex, toCentreX, toCentreY);
    long translatedX = fromPosition.x + fromCentreX - toCentreX;
    long translatedY = fromPosition.y + fromCentreY - toCentreY;

    INTERFACE_ASSERT(isInHandledRegion_Local(toMeshIndex, translatedX, translatedY));

    const cMesh* fromMeshC = static_cast<const cMesh*>(fromMesh);
    long fromFace3D = fromMesh->get3DFaceAtPosition(fromPosition);

    long toFace3D;
    if(_translatesBySectionID)
    {
        long section = fromMesh->get3DFaceAttribute(fromFace3D, PE_FaceAttribute_SectionID);
        INTERFACE_CHECK(section != -1, "The mesh passed into iMeshFederation::translatePosition() doesn't look it was generated as a federation tile mesh.");
        if(section == 0)
        {
            cPosition result = toMesh->positionInSection(0, translatedX, translatedY);
            if(result.cell == -1)
            {
                Error("NonFatal", "iMeshFederation::translatePosition() - Bad overlap. Translation failed. Returning an explicitly invalid position.");
            }
            return result;
        }
        long translatedHorizontalCoords[6];
        float verticalCoords[3];
        long v;
        for(v = 0; v != 3; ++v)
        {
            fromMesh->get3DFaceVertex(fromFace3D, v, translatedHorizontalCoords[v * 2], translatedHorizontalCoords[v * 2 + 1], verticalCoords[v]);
            translatedHorizontalCoords[v * 2] += fromCentreX - toCentreX;
            translatedHorizontalCoords[v * 2 + 1] += fromCentreY - toCentreY;
        }
        const cMesh* toMeshC = FromI(toMesh);
        toFace3D = toMeshC->lookup3DFaceInSectionWithCoords(section, translatedHorizontalCoords, verticalCoords);
    }
    else
    {
        const cRepresentedRegionOverlaps* overlaps = fromMeshC->getRepresentedRegionOverlaps();
	    INTERFACE_CHECK(overlaps, "iMeshFederation::translatePosition() called with a mesh instance not generated for a mesh federation");
        toFace3D = overlaps->lookupOverlappedFace(fromFace3D, toMeshIndex);
    }
    if(toFace3D == -1)
    {
        Error("NonFatal", "iMeshFederation::translatePosition() - Bad overlap. Translation failed. Returning an explicitly invalid position.");
        return cPosition();
    }
    return static_cast<const cMesh*>(toMesh)->translateFrom3D(toFace3D, translatedX, translatedY);
}


void
cMeshFederation::getRepresentedRegionsOverlapped(
    const cHorizontalRange& queryRange,
    long* resultsBuffer, long& numberOverlapped
    ) const
{
    cHorizontalRange clippedRange = queryRange;
    if(clippedRange.minX < _startX)
    {
        clippedRange.minX = _startX;
    }
    if(clippedRange.minY < _startY)
    {
        clippedRange.minY = _startY;
    }
    if(clippedRange.maxX > _startX + _width)
    {
        clippedRange.maxX = _startX + _width;
    }
    if(clippedRange.maxY > _startY + _height)
    {
        clippedRange.maxY = _startY + _height;
    }
    numberOverlapped = 0;
    long xFirst, xLast, yFirst, yLast;
    RepresentedRegionRange_OneAxis(_startX, _tileSize, _tilesInX, _overlap, clippedRange.minX, clippedRange.maxX, xFirst, xLast);
    RepresentedRegionRange_OneAxis(_startY, _tileSize, _tilesInY, _overlap, clippedRange.minY, clippedRange.maxY, yFirst, yLast);
    for(long y = yFirst; y <= yLast; ++y)
    {
        for(long x = xFirst; x <= xLast; ++x)
        {
            resultsBuffer[numberOverlapped++] = y * _tilesInX + x;
        }
    }
}

iMesh*
cMeshFederation::buildTileMeshFromContent(long tileIndex, const iContentChunkInstance* const* instancePointers, long numberOfInstances, const char *const* options, iOutputStream* os)
{
#ifndef PATHENGINE_FULL_RELEASE
    {
        long i;
        for(i = 0; i != numberOfInstances; ++i)
        {
            if(!instancePointers[i]->getContentChunk()->hasGroundComponent())
            {
                continue;
            }
            const iFaceVertexMesh& mesh = *instancePointers[i]->getGroundPointer();
            long f;
            for(f = 0; f != mesh.faces(); ++f)
            {
                if(mesh.faceAttribute(f, PE_FaceAttribute_MarksPortal) == 1)
                {
                    Error("NonFatal", "buildTileMeshFromContent() - Non-terrain portals are not allowed. Aborting, returning zero.");
                    return 0;
                }
                if(mesh.faceAttribute(f, PE_FaceAttribute_SectionID) == 0)
                {
                    Error("NonFatal", "buildTileMeshFromContent() - Terrain stand-in geometry is generated by this method, and should not be passed in. Aborting, returning zero.");
                    return 0;
                }
            }
        }
        std::map<long, long> sectionIDCount;
        for(i = 0; i != numberOfInstances; ++i)
        {
            if(!instancePointers[i]->getContentChunk()->hasGroundComponent())
            {
                continue;
            }
            long sectionID = FromI(instancePointers[i])->getSectionID();
            if(sectionID == -1)
            {
                Error("NonFatal", "buildTileMeshFromContent() - Content chunk instance encountered with sectionID set to -1. Aborting, returning zero.");
                return 0;
            }
            if(sectionID == 0)
            {
                Error("NonFatal", "buildTileMeshFromContent() - Content chunk instance encountered with sectionID set to 0. This value is reserved for terrain stand-in geometry. Aborting, returning zero.");
                return 0;
            }
            if(sectionIDCount[sectionID] > 0)
            {
                Error("NonFatal", "buildTileMeshFromContent() - Content chunk instance sectionID values are not unique. Aborting, returning zero.");
                return 0;
            }
            ++sectionIDCount[sectionID];
        }
    }
#endif

    cHorizontalRange representedRegion;
    getRepresentedRegion_World(tileIndex, representedRegion);

    cHorizontalRange footprintsRange = representedRegion;

    long i;
    for(i = 0; i != numberOfInstances; ++i)
    {
        if(FromI(instancePointers[i])->hasGroundFootprint())
        {
            cHorizontalRange footprintRange;
            FromI(instancePointers[i])->getGroundFootprintRange(footprintRange);
            AddRange(footprintsRange, footprintRange);
        }
    }

    cTerrainStandinForRange terrain(footprintsRange);

    std::vector<const iFaceVertexMesh*> offsetGeometryObjects;
        
    long centreX, centreY;
    getTileCentre(tileIndex, centreX, centreY);
    for(i = 0; i != numberOfInstances; ++i)
    {
        if(instancePointers[i]->getContentChunk()->hasGroundComponent())
        {
            offsetGeometryObjects.push_back(new cHorizontallyOffsetFVM(instancePointers[i]->getGroundPointer(), -centreX, -centreY));
        }
    }
    offsetGeometryObjects.push_back(new cHorizontallyOffsetFVM(&terrain, -centreX, -centreY));

    tMesh_3D mesh3D;
    std::vector<long>* surfaceTypes;
    std::vector<long>* sectionIDs;
    std::vector<long>* userData;
    cExportOptions exportOptions;

    {
        const char* value;
        value = GetValueForAttribute(options, "filterFacesWithSlopeAbove");
        if(value)
        {
            Error("Warning", "'filterFacesWithSlopeAbove' attribute ignored in iMeshFederation::buildTileMeshFromContent()");
        }
        value = GetValueForAttribute(options, "optimiseWithThreshold");
        if(value)
        {
            Error("Warning", "'optimiseWithThreshold' attribute ignored in iMeshFederation::buildTileMeshFromContent()");
        }
    }
    {
        long layers = ValueAsLongWithDefault(options, "numberOfTerrainLayers", 1);
        if(layers != 1)
        {
            Error("Warning", "'numberOfTerrainLayers' attribute forced to 1 iMeshFederation::buildTileMeshFromContent()");
        }
    }
    {
        bool value = ValueAsBoolWithDefault(options, "explicitlyManagedEdgeConnections", true);
        if(value != true)
        {
            Error("Warning", "'explicitlyManagedEdgeConnections' attribute forced to true iMeshFederation::buildTileMeshFromContent()");
        }
        exportOptions.explicitlyManagedEdgeConnections = true;
    }

    if(os)
    {
        nSingletons::pathEngine().saveContentData(&offsetGeometryObjects[0], SizeL(offsetGeometryObjects), "tok", os);
    }

    bool completedSuccessfully = PerformContentProcessing(
            offsetGeometryObjects,
            exportOptions,
            false, 0.f, 0.f, // no external edge optimisation
            1,
            options,
            mesh3D,
            surfaceTypes,
            sectionIDs,
            userData
            );

    for(i = 0; i != SizeL(offsetGeometryObjects); ++i)
    {
        delete offsetGeometryObjects[i];
    }

    if(!completedSuccessfully)
    {
        return 0;
    }

    iMesh* tileMesh = nSingletons::pathEngine().constructMeshFrom3D(mesh3D, surfaceTypes, sectionIDs, userData, options);

    for(i = 0; i != numberOfInstances; ++i)
    {
        if(!instancePointers[i]->getContentChunk()->hasAnchorsAndShapesComponent())
        {
            continue;
        }
        long sectionID = FromI(instancePointers[i])->getSectionID();
        std::ostringstream prefix;
        prefix << sectionID << ':';
        cHorizontallyOffsetAnchorsAndShapes offsetAnchorsAndShapes(instancePointers[i]->getAnchorsAndShapesPointer(), -centreX, -centreY);
        AddAnchorsAndPinnedShapes(nSingletons::pathEngine(), tileMesh, offsetAnchorsAndShapes, prefix.str().c_str(), 1);
    }

    return tileMesh;
}
