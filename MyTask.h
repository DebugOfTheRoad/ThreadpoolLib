#pragma once
#include "task.h"

/**
* @class CDetectTask ����
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

