#pragma once

#include <windows.h>

/** 
* @class CMyMutex ������
* @brief ��װ��CRITICAL_SECTION����Ĳ�������
*/
class CMyMutex
{
public:
	CMyMutex(void);
	~CMyMutex(void);
public:
	bool Lock();
	bool Unlock();
private:
	CRITICAL_SECTION m_cs;
};