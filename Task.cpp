#include "Task.h"

/// ���캯��
CTask::CTask(int id):m_taskID(id)
{
}

/// ��������
CTask::~CTask(void)
{
}

/// �����ڴ溯��
void CTask::Destroy() 
{
}

/// ��ȡ�����ʶ
int CTask::getID()
{ 
	return m_taskID; 
}