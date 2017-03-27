#include <iostream>
#include "MyThreadPool.h"
#include "MyThread.h"
#include"TestTask.h"

int main(int argc,char**argv)
{
	CTestTask *p = NULL;
	CMyThreadPool threadpool(10);
	for(int i = 0; i < 100; i++)
	{
 		p = new CTestTask(i);
		threadpool.addTask(p, PRIORITY::NORMAL);
	}
	p = new CTestTask(102200);
	threadpool.addTask(p, PRIORITY::HIGH);
	
	//���߳�ִ����������
	{
		Sleep(1000 * 20);
	}
	threadpool.destroyThreadPool();

	return 0;
}