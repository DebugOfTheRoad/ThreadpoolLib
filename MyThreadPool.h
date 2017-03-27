#pragma once

#include<list>
#include "MyMutex.h"
#include "MyStack.h"
#include "MyList.h"
#include"MyQueue.h"

class CMyThread;
class CTask;

/** 
* @enum PRIORITY �������ȼ� 
*/
enum PRIORITY
{
	NORMAL,
	HIGH
};

/** 
* @class CBaseThreadPool �̳߳ػ���
*/
class CBaseThreadPool
{
public:
	virtual bool SwitchActiveThread(CMyThread *ptd) = 0;
};

/**
* @class CMyThreadPool �̳߳�
* �̳߳ذ�������Ҫ�أ������߳�ջ����߳������������
*/
class CMyThreadPool : public CBaseThreadPool
{
public:
	CMyThreadPool(int num);
	~CMyThreadPool(void);
public:
	virtual CMyThread* PopIdleThread();
	virtual bool SwitchActiveThread(CMyThread* pThread);

public:
	/// ��������̳߳�
	bool addTask(CTask *t,PRIORITY priority);
	/// ��ʼ����
	bool start();
	/// �����̳߳�
	bool destroyThreadPool();
	/// ��ȡ��̸߳���
	int GetActiveThreadNum() { return m_ActiveThreadList.getSize(); }

private:
	/// �̳߳�����
	int m_nThreadNum;
	/// �˳��ı��
	bool m_bIsExit;

	/// �����߳�ջ(���new�������߳�ָ��)
	CMyStack m_IdleThreadStack;
	/// ��߳��б�(���new�������߳�ָ��)
	CMyList m_ActiveThreadList;
	/// �������(���new����������ָ��)
	CMyQueue m_TaskQueue;
};