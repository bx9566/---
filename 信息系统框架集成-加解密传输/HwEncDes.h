#pragma once
#include<iostream>
using namespace std;
#include "CEncDesProtocol.h"
#include "des���ܽ���.h"
class HwEncDes : public CEncDesProtocol,public des
{
public:
	// ���� ����--������
	virtual int EncData(unsigned char *plain, int plainlen, unsigned char *cryptdata, int *cryptdatalen);
	// ���� ����-->>����
	virtual int DecData(unsigned char *cryptdata, int cryptdatalen, unsigned char *plain, int *plainlen);
};


