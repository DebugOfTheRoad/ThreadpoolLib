#include "MyTask.h"

/**
* @brief ����һ������
* @param[in] id ������
*/
CMyTask::CMyTask(int id):CTask(id)
{
}

/// Ĭ����������
CMyTask::~CMyTask(void)
{
}

/// delete this
void CMyTask::Destroy()
{
	delete this;
}

/// CMyTask���ص�����ִ�к���
void CMyTask::taskProc()
{
	for(int i=0;i<10000;i++)
	{
		for(int j=0;j<10000;j++)
		{
			int temp=1;
			temp++;
		}
	}
}