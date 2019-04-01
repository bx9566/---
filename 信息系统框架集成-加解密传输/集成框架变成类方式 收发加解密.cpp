#define _CRT_SECURE_NO_WARNINGS
#include "iostream"

using namespace std;

#include "SocketProtocol.h"
#include "SckFactoryImp1.h"
#include "SckFactoryImp2.h"
#include "CEncDesProtocol.h"
#include "HwEncDes.h"
#include "des���ܽ���.h"

// �������ڶ�̳��е�Ӧ��
//class MainOp : public CSocketProtocol,public CEncDesProtocol
//{
//public:
//
//protected:
//
//private:
//
//};

class MainOp
{
public:
	MainOp()
	{
		this->ed = NULL;
		this->sp = NULL;
	}
	MainOp(CSocketProtocol *sp,CEncDesProtocol *ed)
	{
		this->ed = ed;
		this->sp = sp;
	}
	void setSp(CSocketProtocol *sp)
	{
		this->sp = sp;
	}
	void setEd(CEncDesProtocol *ed)
	{
		this->ed = ed;
	}

public:
	int SckSendAndRec(unsigned char *in,int inlen,unsigned char *out,int *outlen)
	{ 
		int ret = 0;
		ret = this->sp->cltSocketInit();
		if ( ret != 0)
		{
			goto End;
		}
		ret = sp->cltSocketSend(in,inlen);
		if ( ret != 0)
		{
			goto End;
		}
		ret = sp->cltSocketRev(out,outlen);
		if ( ret != 0)
		{
			goto End;
		}
	End:
		ret = this->sp->cltSocketDestory();
		return 0;
	}

	//�ÿ��ʽһ������ ��Ϊ�����ʽ 
	int SckSendAndRecDecEnc(unsigned char *in,int inlen,unsigned char *out,int *outlen)
	{ 
		int ret = 0;
		unsigned char data[4096];
		int datalen = 0;
		ret = this->sp->cltSocketInit();
		if ( ret != 0)
		{
			goto End;
		}

		ret = this->ed->EncData(in,inlen,data,&datalen);// ���ݷ���֮ǰҪ���ܣ����͵�������
		if ( ret != 0)
		{
			goto End;
		}

		ret = this->sp->cltSocketSend(data,datalen);// ��������
		if ( ret != 0)
		{
			goto End;
		}

		ret = sp->cltSocketRev(data,&datalen);// �յ��������ģ�Ҫ���н���
		if ( ret != 0)
		{
			goto End;
		}

		ret = ed->DecData(data,datalen,out,outlen);//����
		if ( ret != 0)
		{
			goto End;
		}
	End:
		ret = sp->cltSocketDestory();
		return 0;
	}
protected:

private:
	CSocketProtocol *sp;
	CEncDesProtocol *ed;
};

//дһ�����
int main()
{
	int ret = 0;
	unsigned char in[4096];
	int inlen;
	unsigned char out[4096];
	int outlen = 0;

	strcpy((char *)in,"aaaaaabbbbbbbdddd");
	inlen = 9;

	CSocketProtocol *sp = NULL;
	CSocketProtocol *sp2 = NULL;
	sp = new CSckFactoryImp1;
	sp2 = new CSckFactoryImp2;

	CEncDesProtocol *ed = NULL;
	ed = new HwEncDes;
	
	MainOp *myMainOp = new MainOp;//��ʱ�����޲ι��캯��MainOp()����Ҫ���ã�����
	myMainOp->setSp(sp);
	myMainOp->setEd(ed);

	// �ڶ�������
	myMainOp->SckSendAndRec(in,inlen,out,&outlen);
	if ( ret != 0)
	{
		cout << "func SckSendAndRec() err:" << ret << endl;
		return ret;
	}

	//�ӽ���
	ret = myMainOp->SckSendAndRecDecEnc(in,inlen,out,&outlen);
	if ( ret != 0)
	{
		cout << "func SckSendAndRecDecEnc() err:" << ret << endl;
		return ret;
	}

	MainOp *m2 = new MainOp(sp,ed);//��ʱ�����вι��캯����MainOp(CSocketProtocol *sp,CEncDesProtocol *ed������Ҫ����
	m2->SckSendAndRecDecEnc(in,inlen,out,&outlen);
	if ( ret != 0)
	{
		cout << "func SckSendAndRecDecEnc() err:" << ret << endl;
		return ret;
	}

	delete sp;
	delete ed;
	delete myMainOp;
	delete sp2;
	delete m2;

	cout << "hello..."<< endl;

	system("pause");

}