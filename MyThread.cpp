#include "MyThread.h"
#include"task.h"
#include "MyThreadPool.h"
#include<cassert>

// �˳�����
#define EXIT_CODE (0xDEAD)

CMyThread::CMyThread(CBaseThreadPool *threadPool)
{
	m_pTask = NULL;
	m_pThreadPool = threadPool;
	m_hEvent = CreateEvent(NULL, false, false, NULL);
	m_bIsExit = false;
	m_bHasExit = false;
}

CMyThread::~CMyThread(void)
{
	CloseHandle(m_hEvent);
	CloseHandle(m_hThread);
}

/// ��ʼ�߳�
bool CMyThread::startThread()
{
	m_hThread = CreateThread(0, 0, threadProc, this, 0, &m_threadID);
	if(m_hThread == INVALID_HANDLE_VALUE)
	{
		return false;
	}
	return true;
}

/// �����߳�
bool CMyThread::suspendThread()
{
	ResetEvent(m_hEvent);
	return true;
}

/// ����������֪ͨ�̼߳���ִ��
bool CMyThread::resumeThread()
{
	SetEvent(m_hEvent);
	return true;
}

/// �߳�ִ�к���
DWORD WINAPI CMyThread::threadProc(LPVOID pParam)
{
	CMyThread *pThread = (CMyThread*)pParam;
	DWORD ret = 1; // �̳߳�������ʱ����
	do // ���߳�δ�˳�ʱѭ���ȴ�ִ������
	{
		if(ret == WAIT_OBJECT_0)// 0
		{
			if(pThread->m_pTask)
			{
				pThread->m_pTask->taskProc();// ִ������
				pThread->m_pTask->Destroy();
				pThread->m_pTask = NULL;
				pThread->m_pThreadPool->SwitchActiveThread(pThread);
			}
		}
		// �ȴ�����
		ret = WaitForSingleObject(pThread->m_hEvent, INFINITE);
	}while(!pThread->m_bIsExit);
	// ����߳����˳�
	pThread->m_bHasExit = true;
	return EXIT_CODE;
}

/// ������������߳���
bool CMyThread::assignTask(CTask *pTask)
{
	assert(pTask);
	if(!pTask)
		return false;
	m_pTask = pTask;

	return true;
}

/// ��ʼִ������
bool CMyThread::startTask()
{
	resumeThread();
	return true;
}