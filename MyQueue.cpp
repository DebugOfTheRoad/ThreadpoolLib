#include "MyQueue.h"
#include"task.h"

CMyQueue::CMyQueue(void)
{
}


CMyQueue::~CMyQueue(void)
{
}

/**
* @brief ȡ����������
* @remark ������Ϊ��ʱpopΪNULL
*/
CTask* CMyQueue::pop()
{
	CTask *p = NULL;
	m_mutex.Lock();
	if(!m_TaskQueue.empty())
	{
		p = m_TaskQueue.front();
		m_TaskQueue.pop_front();
	}
	m_mutex.Unlock();
	return p;
}

/**
* @brief ���β����һ������
* @param[in] *t ����ָ��
* @remark ��ָ��Ϊ��ʱʧ��
*/
bool CMyQueue::push(CTask *t)
{
	if(!t)
	{
		return false;
	}
	m_mutex.Lock();
	m_TaskQueue.push_back(t);
	m_mutex.Unlock();
	return true;
}

/**
* @brief �ж���������Ƿ�Ϊ��
* @return ����Ϊ�շ���true
*/
bool CMyQueue::isEmpty()
{
	bool ret = false;
	m_mutex.Lock();
	ret = m_TaskQueue.empty();
	m_mutex.Unlock();
	return ret;
}

/**
* @brief ��������һ������
* @param[in] *t ����ָ��
*/
bool CMyQueue::pushFront(CTask *t)
{
	if(!t)
	{
		return false;
	}
	m_mutex.Lock();
	m_TaskQueue.push_front(t);
	m_mutex.Unlock();
	return true;
}

/**
* @brief ����������
* @warning �����ն����е�ָ����ڴ�
*/
bool CMyQueue::clear()
{
	m_mutex.Lock();
	m_TaskQueue.clear();
	m_mutex.Unlock();
	return true;
}