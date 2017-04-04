#include "MyList.h"
#include <cassert>
#include"MyThread.h"

/**
* @brief ���߳��б����һ���߳�
* @param[in] *t �߳�ָ��
* @return �ɹ�����true��tΪ��ʱ����false
* @retval bool
*/
bool CMyList::addThread(CMyThread *t)
{
	assert(t);
	if(!t)
		return false;
	m_mutex.Lock();
	m_list.push_back(t);
	m_mutex.Unlock();
	return true;
}

/**
* @brief ���߳��б��Ƴ�һ���߳�(ֻ�Ƴ�����delete)
* @param[in] *t �߳�ָ��
* @return �ɹ�����true��tΪ��ʱ����false
* @retval bool
*/
bool CMyList::removeThread(CMyThread *t)
{
	assert(t);
	if(!t)
		return false;
	m_mutex.Lock();
	m_list.remove(t);
	m_mutex.Unlock();
	return true;
}

/**
* @brief ��ȡ�߳��б�Ĵ�С
* @return �̸߳���
* @retval int
*/
int CMyList::getSize()
{
	m_mutex.Lock();
	int size = m_list.size();
	m_mutex.Unlock();
	return size;
}

/**
* @brief �ж��߳��б��Ƿ�Ϊ��
* @return �б�Ϊ��ʱ����true
* @retval bool
*/
bool CMyList::isEmpty()
{
	m_mutex.Lock();
	bool ret = m_list.empty();
	m_mutex.Unlock();
	return ret;
}

/**
* @brief ɾ���߳��б��е��߳�(deleteָ��)
* @return true
* @retval bool
*/
bool CMyList::clear()
{
	m_mutex.Lock();
	std::list<CMyThread*>::iterator iter = m_list.begin();
	for(; iter != m_list.end(); iter++)
	{
		delete (*iter);
	}
	m_list.clear();
	m_mutex.Unlock();
	return true;
}