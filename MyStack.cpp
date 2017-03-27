#include "MyStack.h"
#include<cassert>
#include"MyThread.h"

CMyStack::CMyStack(void)
{
}

CMyStack::~CMyStack(void)
{
}

/**
* @brief ȡ���߳�ջ������һ���߳�
* @return �߳�ָ��
* @remark ջ��ʱ����NULL
*/
CMyThread* CMyStack::pop()
{
	m_mutext.Lock();
	if(!m_stack.empty())
	{
		CMyThread *t = m_stack.top();
		m_stack.pop();
		m_mutext.Unlock();
		return t;
	}
	m_mutext.Unlock();
	return NULL;
}

/**
* @brief ���߳�ջ���һ���߳�
* @param[in] *t �߳�ָ��
*/
bool CMyStack::push(CMyThread *t)
{
	assert(t);
	if(!t)
		return false;
	m_mutext.Lock();
	m_stack.push(t);
	m_mutext.Unlock();
	return true;
}

/**
* @brief ��ȡ�߳�ջ�Ĵ�С
* @return �̸߳���
*/
int CMyStack::getSize()
{
	m_mutext.Lock();
	int size = m_stack.size();
	m_mutext.Unlock();
	return size;
}

/**
* @brief �ж��߳�ջ�Ƿ��
* @return ��ʱ����true
*/
bool CMyStack::isEmpty()
{
	m_mutext.Lock();
	bool ret = m_stack.empty();
	m_mutext.Unlock();
	return ret;
}

/**
* @brief ��տ����߳�ջ
* @remark ��������߳�ָ����ڴ�
*/
bool CMyStack::clear()
{
	m_mutext.Lock();
	CMyThread *pThread = NULL;
	while(!m_stack.empty())
	{
		pThread = m_stack.top();
		m_stack.pop();
		// ���߳���Ȼ�˳�
		pThread->m_bIsExit = true;
		pThread->resumeThread();
		// �ȴ��߳��˳�
		while (!pThread->m_bHasExit)
		{
			Sleep(1);
		}
		delete pThread;
	}
	m_mutext.Unlock();
	return true;
}