/** 
* @file MyStack.h
* @brief �����߳�ջ
*/

#pragma once
#include<stack>
#include "MyMutex.h"

class CMyThread;

/**
* @class CMyStack 
* @brief �����߳�(ָ��)�����ջ��
*/
class CMyStack
{
public:
	/// Ĭ�Ϲ��캯��
	CMyStack() { }
	/// Ĭ����������
	~CMyStack() { }

	CMyThread* pop();
	bool push(CMyThread *t);
	int getSize();
	bool isEmpty();
	bool clear();
private:
	/// ����ջ
	std::stack<CMyThread*> m_stack;
	/// ������
	CMyMutex m_mutext;
};