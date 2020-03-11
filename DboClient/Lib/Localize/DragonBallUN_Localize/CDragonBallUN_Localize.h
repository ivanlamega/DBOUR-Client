#pragma once
#include "stdafx.h"
#include <vector>
#include "NtlClientService.h"
#include <sstream>
#include <utility>

class CDragonBallUN_Localize : public INtlClientService
{

public:
	CDragonBallUN_Localize(void);
	virtual ~CDragonBallUN_Localize(void);

public:
	virtual bool							Begin(void* pData);
	virtual void							End(void);

	virtual eDBO_SERVICE_PUBLISHER			GetPublisherID(void);

	virtual void*							GetServiceData(int nIndex);

	virtual bool							CreateSecuritySolution(void);
	virtual void							DeleteSecuritySolution(void);
	virtual void							AttachSecuritySolutionWindow(HWND hWnd);
	virtual void							AttachSecuritySolutionUserID(const char* pUserID);
	virtual void							SecurityAuthServer(void* pData, int nSize);
	virtual void							CheckGameMon(void);
	virtual bool							IsEmptySecurityRetData(void);
	virtual void							AddSecurityRetData(unsigned int uiRetFlag, unsigned int uiRetCode, sSEC_RET_DATA* pRetData);
	virtual bool							PopSecurityRetData(unsigned int& uiRetFlag, unsigned int& uiRetCode, sSEC_RET_DATA** ppRetData);
private:
	std::vector<std::string> explode(std::string const & s, char delim);
	std::string 	m_pAuthLoginData;
};

INtlClientService* GetServiceInterface(void)
{
	static CDragonBallUN_Localize g_clService;
	return &g_clService;
}