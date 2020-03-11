#include "StdAfx.h"
#include ".\extfilter.h"
#include <algorithm>

CExtFilter::CExtFilter(void)
{
	Create();
}

CExtFilter::~CExtFilter(void)
{
	Destroy();
}

void CExtFilter::Create()
{
	ExtDefinition();
}

void CExtFilter::Destroy()
{
	m_stlExtMap.clear();
}

BOOL CExtFilter::IsValid( LPCTSTR szPath )
{
	return GetType( szPath ) ? TRUE : FALSE;
}

BOOL CExtFilter::GetExt( LPCTSTR szPath, stlString* pExt )
{
	stlString stlExt;
	stlString::size_type st;

	if( !wcscmp( szPath , L"" ) || szPath == NULL )
		return FALSE;

	stlExt = szPath;

	st = stlExt.find( '.' );

	if( st == stlString::npos )
		return FALSE;
	else
	{
		*pExt = stlExt.substr( st, stlString::npos );
		return TRUE;
	}
    
}

CExtFilter::EXTTYPE CExtFilter::GetType( LPCTSTR szPath )
{
	stlString stlExt;
	stlExtMap::iterator it;

	if( !GetExt( szPath, &stlExt ) )
		return NONE;

	transform ( stlExt.begin(), stlExt.end(),   // source
			    stlExt.begin(),					// destination
				tolower );						// operation

    it = m_stlExtMap.find( stlExt );

	if( it == m_stlExtMap.end() )
		return NONE;
	else
    	return it->second;
}

void CExtFilter::ExtDefinition()
{
	wchar_t* ImageExts[] = { L".jpe", L".jpg", L".jpeg", L".lif", L".bmp", L".ico", L".pbm", L".pgm", L".pnm", L".ppm", L".png", L".bw"
		L".rgb", L".rgba", L".sgi", L".tga", L".tif", L".tiff", L".pcx", L".xpm", L".psp", L".psd", L".pix", L".pxr", L".cut", L".dcx", L".dds" };
	wchar_t* ResourceExt = L".rsr";
	wchar_t* SurfaceExt = L".srf";
	wchar_t* ComponentExt = L".frm";

    INT	   ExtCount = sizeof( ImageExts ) / 4;

	for( INT i = 0 ; i < ExtCount ; i++ )
	{
		m_stlExtMap[ImageExts[i]] = IMAGE;
    }

	m_stlExtMap[ResourceExt] = RESOURCE;
	m_stlExtMap[SurfaceExt]	 = SURFACE;
	m_stlExtMap[ComponentExt]= COMPONENT;
}