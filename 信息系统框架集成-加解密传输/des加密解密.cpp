#include "des���ܽ���.h"
#include<iostream>
using namespace std;
// �û�ʹ�ú��� desenc ����
int des::DesEnc(unsigned char *pInData, int nInDataLen, unsigned char *poutData, int *poutDataLen)
{
	cin >> *pInData;
	if ('b' == *pInData)
	{ 
		*poutData = 'x';
	}
	if ('x' == *pInData)
	{
		*poutData = 'm';
	}
	cout << "���ܺ�İ���" << *poutData << endl;
	
	return 0;
}
// �û�ʹ�ú��� desdec ����
int des::DesDec(unsigned char *poutData, int poutDataLen,unsigned char *pInData, int *nInDataLen )
{
	if ('x' == *poutData)
	{
		*pInData = 'b';//(unsigned char)
	}
	if ('m' == *poutData)
	{
		*pInData = 'x';
	}
	cout << "���ܺ������" << *pInData << endl;
	
	return 0;
}