/** 
* @file MyQueue.h
* @brief �������
*/

#pragma once
#include<deque>
#include"MyMutex.h"

class CTask;

/**
* @class CMyQueue 
* @brief �������������CTaskָ��
*/
class CMyQueue
{
public:
	/// Ĭ�Ϲ��캯��
	CMyQueue() { }
	/// Ĭ����������
	~CMyQueue() { }

public:
	CTask* pop();
	bool push(CTask *t);
	bool pushFront(CTask *t);//�嵽����
	bool isEmpty();
	bool clear();
private:
	/// �������
	std::deque<CTask*> m_TaskQueue;
	/// ������
	CMyMutex m_mutex;
};