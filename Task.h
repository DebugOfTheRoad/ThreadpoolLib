#pragma once

/** 
* @class CTask ���������(�ṩ�ӿ�)
* @remark �����Ҫ���������ʱ�����ڴ棬����дDestroy
*/
class CTask
{
public:
	/// ���캯��
	CTask(int id);
	/// ��������
	~CTask(void);
	/// �����ڴ溯��
	virtual void Destroy();
	/// ����ִ�к���
	virtual void taskProc() = 0;
	/// ��ȡ�����ʶ
	int getID();
private:
	/// �����ʶ
	int m_taskID;
};