#pragma once
#include<iostream>
using namespace std;
#include "SocketProtocol.h"
class CSckFactoryImp1 :public CSocketProtocol
{
public:
	CSckFactoryImp1()
	{
		;
	}
	virtual ~CSckFactoryImp1()
	{
		;
	}
public:
	virtual int cltSocketInit();//�ͻ��˳�ʼ�� ��ȡhandle
	virtual int cltSocketSend(unsigned char *buf, int buflen);//�ͻ��˷�����
	virtual int cltSocketRev(unsigned char *buf, int *buflen);//�ͻ����ձ���
	virtual int cltSocketDestory();//�ͷ���Դ
private:
	unsigned char *p;
	int len;
};

