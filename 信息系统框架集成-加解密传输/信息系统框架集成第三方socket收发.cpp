#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include "SocketProtocol.h"
#include "SckFactoryImp1.h"
#include "SckFactoryImp2.h"
//��Գ������̣����ʵ��
int SckSendAndRev01(CSocketProtocol *sp, unsigned char *in, int inlen, unsigned char *out, int *outlen)
//int SckSendAndRev(CSocketProtocol *sp, unsigned char *in, int inlen, unsigned char *out, int *outlen)
{
	int ret = 0;
	ret = sp->cltSocketInit();
	if (ret != 0)
	{
		goto End;
	}
	ret = sp->cltSocketSend(in,inlen);
	if (ret != 0)
	{
		goto End;
	}
	//cout << "��һ������socket��Ʒ��������" << in << endl;
	ret = sp->cltSocketRev(out,outlen);
	if (ret != 0)
	{
		goto End;
	}
	//cout << "��һ������socket��Ʒ���յ�����" << out << endl;
	End:
	ret = sp->cltSocketDestory();
	return 0;
}
//��� 
int main01()
{
	int ret = 0;
	unsigned char in[4096];
	int inlen;
	unsigned char out[4096];
	int outlen=0;
	strcpy((char*)in, "aaaaaaaaaaa");
	inlen = 9;
    CSocketProtocol *sp = NULL;
	//��һ������socket�շ���Ʒ����
	sp = new CSckFactoryImp1;
	ret = SckSendAndRev01(sp, in, inlen, out, &outlen);
	if (ret != 0)
	{
		printf("func SckSendAndRev() err:%d\n",ret);
		return ret;
	}
	
	delete sp;
	CSocketProtocol *sp2 = NULL;
	//��һ������socket�շ���Ʒ����
	sp2 = new CSckFactoryImp2;
	ret = SckSendAndRev01(sp2, in, inlen, out, &outlen);
	if (ret != 0)
	{
		printf("func SckSendAndRev() err:%d\n", ret);
		return ret;
	}

	delete sp2;
	system("pause");
	return ret;
}
 