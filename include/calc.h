#ifndef CALC_H
#define CALC_H

#include <string>

using namespace std;

class AmaF_Calc
{
protected:
	string exp;	//��¼�û�����ı��ʽ
	int pos;	//��¼ɨ�赽��λ��
	double amafOperate(double a,char symbol,double b);	//˫Ŀ���㺯��
	double amafOperate(double a,char symbol);	//���صĵ�Ŀ���㺯��
	char amafCompare(char a,char b);	//�Ƚ�����������ȼ�
	bool amafIsDigit(char c)	//�ж��ǲ������ֻ���
	{if((c<='9'&&c>='0')||(c=='e')||(c=='p'))return true;return false;}
	char amafFuncSymbol();	//���û�����ĺ���ת�����ַ��ͼǺ�
	double amafAtof();	//���һ��ʵ�������趨ɨ��λ��

public:
	AmaF_Calc():exp(""),pos(0){}	//���캯��
	void help();	//����
	void evalExpression(string);	//��⺯��
};

#endif