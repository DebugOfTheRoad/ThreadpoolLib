/** 
* @file MyThreadPool.h
* @brief �ҵ��̳߳�
*/

#pragma once

#include "MyStack.h"
#include "MyList.h"
#include"MyQueue.h"

class CMyThread;
class CTask;

/** 
* @enum PRIORITY 
* @brief �������ȼ� 
*/
enum PRIORITY
{
	NORMAL,			/**< �������ȼ� */
	HIGH			/**< �����ȼ� */
};

/** 
* @class CBaseThreadPool 
* @brief �̳߳ػ���
*/
class CBaseThreadPool
{
public:
	/// ���麯�����л���߳�
	virtual bool SwitchActiveThread(CMyThread *ptd) = 0;
};

/**
* @class CMyThreadPool 
* @brief �̳߳�
* @details �̳߳ذ�������Ҫ�أ������߳�ջ����߳������������
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
	inline int GetActiveThreadNum() { return m_ActiveThreadList.getSize(); }

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