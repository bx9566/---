#include<iostream>
using namespace std;

#include "SckFactoryImp2.h"
//��һ�����̲�Ʒ��Χ ϵͳ���
int CSckFactoryImp2::cltSocketInit()
{
	p = NULL;
	len = 0;
	cout << "�ڶ�������socket��Ʒ��ʼ��" << endl;
	return 0;
}
//�ͻ��˳�ʼ�� ��ȡhandle
int CSckFactoryImp2::cltSocketSend(unsigned char *in, int inlen)
{
	//unsigned char *p = new unsigned char(sizeof(buf));

	p = (unsigned char *)malloc(sizeof(unsigned char)*inlen);
	if (p == NULL)
	{
		cout << "���ͷ����ڴ�ʧ��" << endl;
		return -1;
	}
	//cin >> in;
	memcpy(p, in, inlen);
	len = inlen;
	cout << "�ڶ�������socket��Ʒ����" << endl;
	cout << "�������ֵ" << *in << endl;
	return 0;
}//�ͻ��˷�����
int CSckFactoryImp2::cltSocketRev(unsigned char *out, int *outlen)
{
	if (outlen == 0 || out == NULL)
	{
		return -1;
	}
	*outlen = this->len;
	memcpy(out, this->p, this->len);
	cout << "�ڶ�������socket��Ʒ����" << endl;
	cout << "�������ֵ" << *out << endl;
	return 0;
}//�ͻ����ձ��� �ӷ������˻�������
int CSckFactoryImp2::cltSocketDestory()
{
	if (p != NULL)
	{
		free(p);
		p = NULL;
		len = 0;
	}
	cout << "�ڶ�������socket��Ʒ�ͷ���Դ" << endl;
	return 0;
}//�ͷ���Դ
