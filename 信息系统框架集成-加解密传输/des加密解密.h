#pragma once

class des
{
public://���ܽ��ܵĽӿ�
	//�û�ʹ�õĺ��� ����
	virtual int DesEnc(unsigned char *pInData,int nInDataLen,unsigned char *poutData,int *poutDataLen);
	// �û�ʹ�ú��� des ����
	virtual int DesDec(unsigned char *pInData, int nInDataLen, unsigned char *poutData, int *poutDataLen);
};

