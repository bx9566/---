#pragma once

// ���� ����  ������Э��

class CEncDesProtocol
{
public:
	CEncDesProtocol()
	{

	}
	virtual~CEncDesProtocol()
	{

	}
	// ���� ����--������
	virtual int EncData(unsigned char *plain, int plainlen, unsigned char *cryptdata, int *cryptdatalen) = 0;
	// ���� ����-->>����
	virtual int DecData(unsigned char *cryptdata, int cryptdatalen, unsigned char *plain, int *plainlen) = 0;
};