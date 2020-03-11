#include "StdAfx.h"
#include "MTPropertyContainer.h"
#include "NtlDebug.h"

CMTPropertyContainer::CMTPropertyContainer()
{

}

CMTPropertyContainer::~CMTPropertyContainer()
{

}

RwBool CMTPropertyContainer::Load()
{
	NTL_FUNCTION("__FUNCTION__");

	//////////////////////////////////////////////////////////////////////////
	// 월드용 로드
	if(!LoadNtlWorld(""))
	{
		NTL_RETURN(FALSE);
	}

	if(!LoadWater(".\\script\\waterproperty.xml"))
	{
		NTL_RETURN(FALSE);
	}

	if(!LoadShoreLine(".\\script\\ShoreLineProp.xml"))
	{
		NTL_RETURN(FALSE);
	}
	//////////////////////////////////////////////////////////////////////////

	if(!LoadObject(".\\devdata\\object\\ObjectPropertyList.XML"))
	{
		NTL_RETURN(FALSE);
	}

	if(!LoadSound(".\\script\\Environment.tbl"))
	{
		NTL_RETURN(FALSE);
	}

	if(!LoadCharacter(".\\devdata\\character\\characterpropertyList.xml"))
	{
		NTL_RETURN(FALSE);
	}

	if(!LoadCharacter(".\\devdata\\character\\mobpropertyList.xml"))
	{
		NTL_RETURN(FALSE);
	}

	if(!LoadCharacter(".\\devdata\\character\\npcpropertyList.xml"))
	{
		NTL_RETURN(FALSE);
	}

	if(!LoadCharacter(".\\devdata\\character\\VehiclePropertyList.xml"))
	{
		NTL_RETURN(FALSE);
	}

	if(!LoadItem(".\\devdata\\item\\itempropertylist.xml"))
	{
		NTL_RETURN(FALSE);
	}

	if(!LoadEffect(".\\Effect\\VisualEffect.eff"))
	{
		NTL_RETURN(FALSE);
	}

	if(!LoadGui(".\\script\\guiproperty.xml"))
	{
		NTL_RETURN(FALSE);
	}

	if(!LoadPlant(".\\script\\PlantProperty.xml"))
	{
		NTL_RETURN(FALSE);
	}

	if(!LoadWeather(".\\script\\WeatherProperty.xml", 0))
	{
		NTL_RETURN(FALSE);
	}

	if(!LoadWeather(".\\script\\WeatherProperty_LV1.xml", 1))
	{
		NTL_RETURN(FALSE);
	}

	if(!LoadWeather(".\\script\\WeatherProperty_LV2.xml", 2))
	{
		NTL_RETURN(FALSE);
	}

	if(!LoadSoundField(".\\script\\BgmSoundProperty.xml", "FIELD_SOUND_BGM"))
	{
		NTL_RETURN(FALSE);
	}

	if(!LoadSoundField(".\\script\\EnvSoundProperty.xml", "FIELD_SOUND_ENV"))
	{
		NTL_RETURN(FALSE);
	}

	if(!LoadSoundField(".\\script\\ShareSoundProperty.xml", "FIELD_SOUND_SHARE"))
	{
		NTL_RETURN(FALSE);
	}

	NTL_RETURN(TRUE);
}
