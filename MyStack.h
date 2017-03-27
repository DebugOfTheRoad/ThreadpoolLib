#pragma once
#include<stack>
#include "MyMutex.h"

class CMyThread;

/**
* @class CMyStack �����߳�ջ
* @brief �����߳�(ָ��)�����ջ��
*/
class CMyStack
{
public:
	CMyStack(void);
	~CMyStack(void);
public:
	CMyThread* pop();
	bool push(CMyThread *t);
	int getSize();
	bool isEmpty();
	bool clear();
private:
	std::stack<CMyThread*> m_stack;
	CMyMutex m_mutext;
};