#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include "SocketProtocol.h"
#include "SckFactoryImp1.h"
#include "SckFactoryImp2.h"
#include "CEncDesProtocol.h"
#include "HwEncDes.h"
#include "des���ܽ���.h"
//��Գ������̣����ʵ��
int SckSendAndRev02(CSocketProtocol *sp, unsigned char *in, int inlen, unsigned char *out, int *outlen)
//int SckSendAndRev(CSocketProtocol *sp, unsigned char *in, int inlen, unsigned char *out, int *outlen)
{
	int ret = 0;
	ret = sp->cltSocketInit();
	if (ret != 0)
	{
		goto End;
	}
	ret = sp->cltSocketSend(in, inlen);
	if (ret != 0)
	{
		goto End;
	}
	//cout << "��һ������socket��Ʒ��������" << in << endl;
	ret = sp->cltSocketRev(out, outlen);
	if (ret != 0)
	{
		goto End;
	}
	//cout << "��һ������socket��Ʒ���յ�����" << out << endl;
End:
	ret = sp->cltSocketDestory();
	return 0;
}
//�ÿ��ʽһ������ Ҫ��Ϊ�����ʽ ��mainclass03_�����.cpp
int SckSendAndRecDecEn03(CSocketProtocol *sp, CEncDesProtocol *ed, unsigned char *in, int inlen, unsigned char *out, int *outlen)
{
	int ret = 0;
	unsigned char data[4096];
	int datalen = 0;
	ret = sp->cltSocketInit();
	if (ret != 0)
	{
		goto End;
	}

	ret = ed->EncData(in, inlen, data, &datalen);// ���ݷ���֮ǰҪ���ܣ����͵�������
	if (ret != 0)
	{
		goto End;
	}

	ret = sp->cltSocketSend(data, datalen);// ��������
	if (ret != 0)
	{
		goto End;
	}

	ret = sp->cltSocketRev(data, &datalen);// �յ��������ģ�Ҫ���н���
	if (ret != 0)
	{
		goto End;
	}

	ret = ed->DecData(data, datalen, out, outlen);//����
	if (ret != 0)
	{
		goto End;
	}
End:
	ret = sp->cltSocketDestory();
	return 0;
}
//��� 
int main02()
{
	int ret = 0;
	unsigned char in[4096];
	int inlen;
	unsigned char out[4096];
	int outlen = 0;
	//strcpy((char*)in, "a");
	inlen = 9;
	CSocketProtocol *sp = NULL;
	//��һ������socket�շ���Ʒ����
	sp = new CSckFactoryImp1;
	/*ret = SckSendAndRev02(sp, in, inlen, out, outlen);
	if (ret != 0)
	{
		printf("func SckSendAndRev() err:%d\n", ret);
		return ret;
	}

	delete sp;//��ͨ������ָ�룬�ͷ����е�����������Դ��Ӧʹ������������*/
	CSocketProtocol *sp2 = NULL;
	//�ڶ�������socket�շ���Ʒ����
	sp2 = new CSckFactoryImp2;
	/*ret = SckSendAndRev02(sp2, in, inlen, out, outlen);
	if (ret != 0)
	{
		printf("func SckSendAndRev() err:%d\n", ret);
		return ret;
	}

	//delete sp2;*/
	// �ӽ���

	CEncDesProtocol *ed = NULL;
	ed = new HwEncDes;
	ret = SckSendAndRecDecEn03(sp2, ed, in, inlen, out, &outlen);//SckSendAndRecDecEn03
	if (ret != 0)
	{
		cout << "func SckSendAndRecDecEnc() err:" << ret << endl;
		return ret;
	}
	delete ed;
	system("pause");
	return ret;
}
