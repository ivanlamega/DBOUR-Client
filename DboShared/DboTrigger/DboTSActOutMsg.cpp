#include "precomp_trigger.h"
#include "DboTSActOutMsg.h"


/**
	Direction action
*/


NTL_TS_IMPLEMENT_RTTI(CDboTSActOutMsg, CNtlTSAction)


CDboTSActOutMsg::CDboTSActOutMsg(void)
	: m_uiTblidx(0xffffffff),
	m_uiActionId(0xffffffff)
{
}

void CDboTSActOutMsg::ApplyScriptDataForScript(const CNtlTSScrProperty& clProperty)
{
	CNtlTSAction::ApplyScriptDataForScript(clProperty);

	//if (clProperty.IsExist("rng"))
	//{
	//	SetRange((float)atof(clProperty.GetValue("rng").c_str()));
	//}

	//if (clProperty.IsExist("type"))
	//{
	//	SetDirectionType((unsigned char)clProperty.GetValueAsInt("type"));
	//}

	//if (clProperty.IsExist("idx"))
	//{
	//	SetDirectionTblIdx((unsigned int)clProperty.GetValueAsInt("idx"));
	//}
}

void CDboTSActOutMsg::TakeScriptDataForScript(CNtlTSScrProperty& clProperty)
{
	CNtlTSAction::TakeScriptDataForScript(clProperty);

	/*sprintf_s(g_NtlTSString, "%f", GetRange());
	clProperty.m_defProperty["rng"] = g_NtlTSString;

	sprintf_s(g_NtlTSString, "%d", GetDirectionType());
	clProperty.m_defProperty["type"] = g_NtlTSString;

	sprintf_s(g_NtlTSString, "%d", GetDirectionTblIdx());
	clProperty.m_defProperty["idx"] = g_NtlTSString;*/
}
