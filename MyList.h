/** 
* @file MyList.h
* @brief �߳��б�
*/

#pragma once
#include <list>
#include "MyMutex.h"

class CMyThread;

/**
* @class CMyList 
* @brief �߳��߳��б�����CMyThreadָ��
*/
class CMyList
{
public:
	/// Ĭ�Ϲ��캯��
	CMyList() { }

	/// Ĭ����������
	~CMyList() { }

public:
	bool addThread(CMyThread *t);
	bool removeThread(CMyThread *t);
	int getSize();
	bool isEmpty();
	bool clear();

private:
	/// �߳��б�
	std::list<CMyThread*> m_list;
	/// ������
	CMyMutex m_mutex;
};