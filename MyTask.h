/** 
* @file MyTask.h
* @brief ����ʵ��
*/

#pragma once
#include "task.h"

/**
* @class CMyTask 
* @brief ��ĿThreadPool������ʵ��
*/
class CMyTask : public CTask
{
public:
	CMyTask(int id);
protected:
	~CMyTask(void);
public:
	_inline virtual void Destroy();
	virtual void taskProc();
};

