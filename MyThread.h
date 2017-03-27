#pragma once
#include <windows.h>

class CTask;
class CBaseThreadPool;

/**
* @class CMyThread �߳���
*/
class CMyThread
{
public:
	CMyThread(CBaseThreadPool *threadPool);
	~CMyThread(void);

public:
	bool startThread();
	bool suspendThread();
	bool resumeThread();
	bool assignTask(CTask *pTask);
	bool startTask();
	static DWORD WINAPI threadProc(LPVOID pParam);

	/// �߳�ID
	DWORD m_threadID;
	/// �߳̾��
	HANDLE m_hThread;
	/// �����˳�
	bool m_bIsExit;
	/// �߳���Ȼ�˳�
	bool m_bHasExit;

private:
	/// �ź�
	HANDLE m_hEvent;
	/// ��ִ������
	CTask *m_pTask;
	/// �����̳߳�
	CBaseThreadPool *m_pThreadPool;	
};