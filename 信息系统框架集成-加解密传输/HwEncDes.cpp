#include "HwEncDes.h"
#include "des���ܽ���.h"


// ���� ����--������
int HwEncDes::EncData(unsigned char *plain, int plainlen, unsigned char *cryptdata, int *cryptdatalen)
{
	int ret = 0;
	//�û�ʹ�õĺ��� ����
	cout << "��Ϊ����" << endl;
	ret = des::DesEnc(plain, plainlen, cryptdata, cryptdatalen);
	if (ret != 0)
	{
		printf("func DesEnc() err:%d\n", ret);
	}
	
	
	return ret;
}
// ���� ����-->>����
int  HwEncDes::DecData(unsigned char *cryptdata, int cryptdatalen, unsigned char *plain, int *plainlen)
{
	int ret = 0;
	// �û�ʹ�ú��� des ����
	cout << "��Ϊ����" << endl;
	ret = des::DesDec(cryptdata, cryptdatalen, plain, plainlen);
	if (ret != 0)
	{
		printf("func DesDec() err:%d\n", ret);
	}

	
	return ret;
}