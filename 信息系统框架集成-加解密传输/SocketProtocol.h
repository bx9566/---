#pragma once
class CSocketProtocol
{
public:
	CSocketProtocol()
	{ 
		;
	}
	virtual ~CSocketProtocol()//����������---��delete sp;
	{
		;
	}
public:
	virtual int cltSocketInit() = 0;//�ͻ��˳�ʼ�� ��ȡhandle
	virtual int cltSocketSend(unsigned char *buf,int buflen) = 0;//�ͻ��˷�����
	virtual int cltSocketRev(unsigned char *buf,int *buflen) = 0;//�ͻ����ձ���
	virtual int cltSocketDestory() = 0;//�ͷ���Դ
};

