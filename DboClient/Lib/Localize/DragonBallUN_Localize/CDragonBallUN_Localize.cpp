#include "stdafx.h"
#include "CDragonBallUN_Localize.h"
#include "base64.h"


CDragonBallUN_Localize::CDragonBallUN_Localize()
{
}


CDragonBallUN_Localize::~CDragonBallUN_Localize()
{
	DeleteSecuritySolution();

	End();
}

//Just a str_replace from php to c++
std::string& str_replace(const std::string &search, const std::string &replace, std::string &subject)
{
	std::string buffer;

	int sealeng = search.length();
	int strleng = subject.length();

	if (sealeng == 0)
		return subject;//no change

	for (int i = 0, j = 0; i < strleng; j = 0)
	{
		while (i + j < strleng && j < sealeng && subject[i + j] == search[j])
			j++;
		if (j == sealeng)//found 'search'
		{
			buffer.append(replace);
			i += sealeng;
		}
		else
		{
			buffer.append(&subject[i++], 1);
		}
	}
	subject = buffer;
	return subject;
}

bool CDragonBallUN_Localize::Begin(void* pData)
{
	if (NULL == pData)
	{
		return false;
	}

	int nKeyStrLen = 4096;

	char* pClipData = new char[nKeyStrLen + 1];
	memcpy(pClipData, pData, nKeyStrLen + 1);
	std::string sData(pClipData);
	std::string sDataWithoutParam = str_replace("-hstrh ", "", sData);
	char *cstr = new char[sDataWithoutParam.length() + 1];
	strcpy(cstr, sDataWithoutParam.c_str());
	m_pAuthLoginData = base64_decode(cstr);
	delete pClipData;
	delete[] cstr;
	return true;
}

void CDragonBallUN_Localize::End(void)
{
}

eDBO_SERVICE_PUBLISHER CDragonBallUN_Localize::GetPublisherID(void)
{
	return eDBO_SERVICE_PUBLISHER_DBONU;
}

void* CDragonBallUN_Localize::GetServiceData(int nIndex)
{	
	if (m_pAuthLoginData.length() != 0)
	{
		std::vector<std::string> arrData = explode(m_pAuthLoginData, ':');
		if(nIndex < arrData.size())
		{
			std::string sReturn = arrData.at(nIndex);
			if (sReturn.length() != 0)
			{
				char* charArrayData = new char[sReturn.length()+1];
				memcpy(charArrayData, sReturn.c_str(), sReturn.length()+1);
				return (void*)charArrayData;
			}
		}
	}
	return NULL;
}

std::vector<std::string> CDragonBallUN_Localize::explode(std::string const & s, char delim)
{
	std::vector<std::string> result;
	std::istringstream iss(s);

	for (std::string token; std::getline(iss, token, delim); )
	{
		result.push_back(std::move(token));
	}

	return result;
}

bool CDragonBallUN_Localize::CreateSecuritySolution(void)
{
	return true;
}

void CDragonBallUN_Localize::DeleteSecuritySolution(void)
{
	
}

void CDragonBallUN_Localize::AttachSecuritySolutionWindow(HWND hWnd)
{
	
}

void CDragonBallUN_Localize::AttachSecuritySolutionUserID(const char* pUserID)
{
	
}

void CDragonBallUN_Localize::SecurityAuthServer(void* pData, int nSize)
{
	
}

void CDragonBallUN_Localize::CheckGameMon(void)
{
	
}

bool CDragonBallUN_Localize::IsEmptySecurityRetData(void)
{
	return true;
}

void CDragonBallUN_Localize::AddSecurityRetData(unsigned int uiRetFlag, unsigned int uiRetCode, sSEC_RET_DATA* pRetData)
{
	
}

bool CDragonBallUN_Localize::PopSecurityRetData(unsigned int& uiRetFlag, unsigned int& uiRetCode, sSEC_RET_DATA** ppRetData)
{	
	return true;
}