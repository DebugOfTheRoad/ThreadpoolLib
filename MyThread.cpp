#include "MyThread.h"
#include"task.h"
#include "MyThreadPool.h"

// 退出代码
#define EXIT_CODE (0xDEAD)

/**
* @brief 在线程池里构造一个线程
* @param[in] *threadPool 线程池指针
*/
CMyThread::CMyThread(CBaseThreadPool *threadPool)
{
	m_pTask = NULL;
	m_pThreadPool = threadPool;
	m_hEvent = CreateEvent(NULL, false, false, NULL);
	m_bIsExit = false;
	m_bHasExit = false;
}

/// 关闭事件及线程句柄
CMyThread::~CMyThread()
{
	CloseHandle(m_hEvent);
	CloseHandle(m_hThread);
}

/// 线程执行函数
DWORD WINAPI CMyThread::threadProc(LPVOID pParam)
{
	CMyThread *pThread = (CMyThread*)pParam;
	DWORD ret = 1; // 线程初次启动时挂起
	do // 当线程未退出时循环等待执行任务
	{
		if(ret == WAIT_OBJECT_0)// 0
		{
			if(pThread->m_pTask)
			{
				pThread->m_pTask->taskProc();// 执行任务
				pThread->m_pTask->Destroy();
				pThread->m_pTask = NULL;
				pThread->m_pThreadPool->SwitchActiveThread(pThread);
			}
		}
		// 等待任务
		ret = WaitForSingleObject(pThread->m_hEvent, INFINITE);
	}while(!pThread->m_bIsExit);
	// 标记线程已退出
	pThread->m_bHasExit = true;
	return EXIT_CODE;
}