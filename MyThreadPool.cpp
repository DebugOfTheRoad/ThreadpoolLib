#include "MyThreadPool.h"
#include "MyThread.h"
#include "Task.h"
#include<cassert>
#include<iostream>
#include "MyQueue.h"

/**
* @brief ����һ������ȷ�����̳߳�
* @param[in] num �̳߳�����
*/
CMyThreadPool::CMyThreadPool(int num)
{
	m_nThreadNum = num;
	m_bIsExit = false;
	for(int i = 0; i < num; i++)
	{
		CMyThread *p = new CMyThread(this);
		m_IdleThreadStack.push(p);
		p->startThread();
	}
}

CMyThreadPool::~CMyThreadPool(void)
{
}

/**
* @brief �ӿ����߳�ջȡ��һ���߳�
* @return ջ�������߳�
*/
CMyThread* CMyThreadPool::PopIdleThread()
{
	CMyThread *pThread = m_IdleThreadStack.pop();
	return pThread;
}

/** 
* @brief ���̴߳ӻ����ȡ������������߳�ջ��.��ȡ֮ǰ�жϴ�ʱ��������Ƿ�������.
* ���������Ϊ��ʱ�Ź���,������������ȡ�������ִ��.
*/
bool CMyThreadPool::SwitchActiveThread( CMyThread *pThread)
{
	CTask *pTask = NULL;
	if(pTask = m_TaskQueue.pop())//������в�Ϊ��,����ȡ����ִ��
	{
		printf("�̡߳�%d��ִ��%d\n", pThread->m_threadID, pTask->getID());

		pThread->assignTask(pTask);
		pThread->startTask();
	}
	else//�������Ϊ�գ����̹߳���
	{
		m_ActiveThreadList.removeThread(pThread);
		m_IdleThreadStack.push(pThread);
	}
	return true;
}

/**
* @brief �������
* @param[in] *t ����(ָ��)
* @param[in] priority ���ȼ�,�����ȼ������񽫱����뵽����.
*/
bool CMyThreadPool::addTask( CTask *t, PRIORITY priority )
{
	assert(t);
	if(!t || m_bIsExit)
		return false;	
	CTask *task = NULL;
	printf("�������%d\n", t->getID());
	if(priority == PRIORITY::NORMAL)
	{
		m_TaskQueue.push(t);//�����������
	}
	else if(PRIORITY::HIGH)
	{
		m_TaskQueue.pushFront(t);//�����ȼ�����
	}

	if(!m_IdleThreadStack.isEmpty())//���ڿ����߳�,���ÿ����̴߳�������
	{
		task = m_TaskQueue.pop();//ȡ����ͷ����
		if(task == NULL)
		{
			// ����ȡ������
			return 0;
		}
		CMyThread *pThread = PopIdleThread();
		printf("�̡߳�%d��ִ��%d\n", pThread->m_threadID, task->getID());
		m_ActiveThreadList.addThread(pThread);
		pThread->assignTask(task);
		pThread->startTask();
	}
	return true;
}

/**
* @brief ��ʼ����
*/
bool CMyThreadPool::start()
{
	return 0;
}

/**
* @brief �����̳߳�
*/
bool CMyThreadPool::destroyThreadPool()
{

	m_bIsExit = true;
	m_TaskQueue.clear();
	m_IdleThreadStack.clear();
	m_ActiveThreadList.clear();
	return true;
}