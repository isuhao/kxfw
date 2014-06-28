//AmaranthF�������м�����
//
//2008/2/4	v0.1
//���Խ������д����ŵ���������
//
//2008/2/5	v0.2
//�����������뷴���Ǻ����������ȣ����ݺͶ���������
//��AmaF_Stack��ջ��������һЩ������������������ջ�����������������ж�ջ�պ�����
//������һЩBug
//
//2008/2/7	v0.3
//�������쳣����������������ʾ
//�����˶�����2 sin3��ʡ�Գ˺ŵı��ʽ��֧��
//�����˳���˵��
//�����ĵ��ԣ�������n��Bug����ͷһ����ᵽԭ�����Գ���ȱ�д����Ҫ����ץ�񡭡���
//
//2008/2/14	v1.0
//��װ��ϣ������й������ϵ�AmaF_Calc�����档

#include "calc.h"
#include <stack>
#include <list>
#include <cmath>
#include <cerrno>
#include <iostream>

//���庯���Ĵ���
#define SIN 'a'	//���Ǻͷ����Ǻ���
#define COS 'b'
#define TAN 'c'
#define ASIN 'd'
#define ACOS 'e'
#define ATAN 'f'
#define LOG 'g'	//10�Ķ���
#define LN 'h'	//��Ȼ����

//���峣��
#define PI 3.145926536	//Բ����
#define EE 2.718281828	//��Ȼ�����ĵ�

//����������
#define IN_SPACE 1
#define DIV_BY_0 2
#define SYNT_ERR 3
#define RNG_ERR 4
#define DOM_ERR 5
#define SYMB_ERR 6

//����
#define SINGLE 'z'	//��Ŀ�����־


using namespace std;

double AmaF_Calc::amafOperate (double a,char symbol,double b)
{
	switch(symbol)
	{
	case '+':
		return a+b;
	case '-':
		return a-b;
	case '*':
		return a*b;
	case '/':
		if(b==0)	//���0������
			throw DIV_BY_0;
		return a/b;
	case '^':
		return pow(a,b);
	case 'E':
		return a*pow(10.0,b);
	default:
		throw SYMB_ERR;
	}
}

double AmaF_Calc::amafOperate (double a,char symbol)
{
	switch(symbol)
	{
	case SIN:
		return sin(a);
	case COS:
		return cos(a);
	case TAN:
		return tan(a);
	case ASIN:
		return asin(a);
	case ACOS:
		return acos(a);
	case ATAN:
		return atan(a);
	case LOG:
		return log10(a);
	case LN:
		return log(a);
	default:
		throw SYMB_ERR;
	}
}

char AmaF_Calc::amafCompare (char a,char b)
{
	switch(a)
	{
	case '+':
	case '-':
		if(b=='+'||b=='-'||b==')'||b=='$')
			return '>';
		else
			return '<';
	case '*':
	case '/':
		if(b=='('||b=='^'||b=='E'||b>=SIN)
			return '<';
		else
			return '>';
	case '^':
		if(b=='('||b=='E'||b>=SIN)
			return '<';
		else
			return '>';
	case 'E':
		if(b=='(')
			return '<';
		else if(b>=SIN)
			throw SYNT_ERR;
		else
			return '>';
	case '(':
		if(b==')')
			return '=';
		else if(b=='$')
			throw SYNT_ERR;
		else
			return '<';
	case '$':
		if(b=='$')
			return '=';
		else if(b==')')
			throw SYNT_ERR;
		else
			return '<';
	default:
		if(a<SIN||a>LN)
			throw SYNT_ERR;
		else if(b=='('||b=='E'||b=='^'||b>=SIN)
			return '<';
		else
			return SINGLE;
	}
}

char AmaF_Calc::amafFuncSymbol ()
{
	string temp(exp.substr (pos,4));
	if(!temp.find("sin"))
	{
		pos+=2;
		return SIN;
	}
	if(!temp.find("cos"))
	{
		pos+=2;
		return COS;
	}
	if(!temp.find("tan"))
	{
		pos+=2;
		return TAN;
	}
	if(!temp.find("asin"))
	{
		pos+=3;
		return ASIN;
	}
	if(!temp.find("acos"))
	{
		pos+=3;
		return ACOS;
	}
	if(!temp.find("atan"))
	{
		pos+=3;
		return ATAN;
	}
	if(!temp.find("log"))
	{
		pos+=2;
		return LOG;
	}
	if(!temp.find("ln"))
	{
		pos++;
		return LN;
	}

	return exp.at(pos);
}

double AmaF_Calc::amafAtof ()
{
	double conFloat=0;

	if(exp.at(pos)=='e')	//�ԡ�e���͡�pi�����������Ĳ���
	{
		pos++;
		return EE;
	}
	else if(exp.find("pi",pos,2)==pos)
	{
		pos+=2;
		return PI;
	}

	conFloat=exp.at(pos)-('0'-0);		//ȡ��������
	pos++;
	for(;amafIsDigit(exp.at(pos))==true;pos++)
	{
		conFloat=10*conFloat+(exp.at(pos)-('0'-0));
	}

	if(exp.at(pos)=='.')	//��С����Ļ��ͼ���ȡС������
	{
		double base=1;
		pos++;
		for(;amafIsDigit(exp.at(pos))==true;pos++)
		{
			base/=10;
			conFloat+=base*(exp.at(pos)-('0'-0));
		}
		return conFloat;
	}
	else if((exp.at(pos)==' ')&&amafIsDigit(exp.at(pos+1)))	//�ж�����֮���Ƿ��пո�
		throw IN_SPACE;
	else
		return conFloat;
}

void AmaF_Calc::help ()
{
	cout<<"\n��������ӵ�д����ŵĻ����������㡢�����뷴���Ǻ������㡢�ݺͶ�������ȹ��ܡ�\n\n"
		"����˵����\n"
		"����0~9��С���㡰.��\n"
		"�����������+ - * / ( )\n"
		"��ѧ���������룺E\n"
		"���Ǻ�����sin,cos,tan,asin�������ң���ͬ��,acos,atan\n"
		"���������10Ϊ�׻�eΪ�ף���^,log,ln\n"
		"Բ��������Ȼ�����ĵף�pi,e\n"
		"���help����ʾ��˵����exit���˳�����\n"<<endl;
	cout<<"����˵����\n"
		"1 �˺����ض�����¿���ʡ�ԣ���7(3+2)����2sin3����ʽ��\n"
		"2 �����ĺ����Լ�����������Сд��ĸ�����ˡ�E����ԭ�����롣\n"
		"3 ��������֮�䲻�����пո񣬵�����λ�ò������ƣ���sin ( 2  ^2+1   )��\n"
		"4 ������ʹ��������������\n"
		"5 ��ѧ�����������룺2.1E3����2100����2.1*10^3����\n"
		"6 ���Ǻ���������û����ơ�\n"
		"7 Ŀǰ���㾫�ȱȽϵͣ����4λС����Ч�����������ڼ�����Ĵ洢ԭ��������ܻ������\n"
		"8 ��������Ĵ�����ʾ���ܻ���Щ������������������������������������Լ����������ı��ʽ��\n"<<endl;
	cout<<endl;
}

void AmaF_Calc::evalExpression (string inexp)
{
	exp=inexp;
	pos=0;
	stack<char,list<char>> symbols;	//��������������ջ
	stack<double,list<double>> figures;	//�����������ջ

	exp+='$';	//��ӽ�����
	symbols.push ('$');	//��ʼ�ַ���ջ

	try
	{
		for(;exp.at(pos)!='$' || symbols.top ()!='$';)	//��ʼ���ɨ��
		{
			if(amafIsDigit(exp.at(pos))==true)	//�������Ļ�����ջ
			{
				figures.push (amafAtof());
				if(errno==EDOM)	//�ж��Ա����Ƿ�Ƿ�
					throw DOM_ERR;
				if(errno==ERANGE)	//�ж��Ƿ����
					throw RNG_ERR;
			}

			else if((pos!=0)&&(exp.at(pos)=='-')&&((exp.at(pos-1)=='(') ||(exp.at(pos-1)=='E')))	//�����ŵ�����ջ
			{
				pos++;
				figures.push (-1.0*amafAtof());
				if(errno==EDOM)
					throw DOM_ERR;
				if(errno==ERANGE)
					throw RNG_ERR;
			}

			else if(exp.at(pos)==' ')	//�����ո��ַ�
				pos++;

			else
			{
				bool prevIsDigit=false;	//��¼ǰһ���ַ��Ƿ�������
				if(pos!=0&&exp.at(pos-1)>='0'&&exp.at(pos-1)<='9')
					prevIsDigit=true;
				char conSymbol=amafFuncSymbol();
				if(prevIsDigit&&(conSymbol>=SIN||conSymbol=='('))	//�Դ��ж��Ƿ������硰2sin 3����ʽ������
					symbols.push ('*');	//���ǵĻ����˺���ջ
				switch(amafCompare(symbols.top (),conSymbol))	//�Ƚ�ջ�����㸳��������������ȼ�
				{
				case '<':
					symbols.push (conSymbol);	//ǰ�����ȼ��ϵ͵Ļ�����ջ������ɨ��
					pos++;
					break;
				case '=':	//�����ڵ�����������ʱ�������ų�ջ
					symbols.pop ();
					pos++;
					break;
				case '>':	//���ȼ��ߵĻ���ȡ����һ�������������ȡ�����������������㣬�����ջ
					{
						double temp1=figures.top ();
						figures.pop ();
						double temp2=amafOperate(figures.top (),symbols.top (),temp1);
						figures.pop ();
						figures.push (temp2);
						symbols.pop ();
						break;
					}
				case SINGLE:	//�����Ŀ���㺯�����ȼ��ϸߣ�ȡ��һ�����������㣬�����ջ
					{
						double temp=amafOperate(figures.top (),symbols.top ());
						figures.pop ();
						symbols.pop ();
						figures.push (temp);
						break;
					}
				}
			}
		}
		if(errno==EDOM)
			throw DOM_ERR;
		else if(errno==ERANGE)
			throw RNG_ERR;
		
		cout<<exp<<"\b = "<<figures.top ()<<endl;
		figures.pop ();
		cout<<endl;
	}
	catch(int errorCode)	//�쳣����
	{
		switch(errorCode)
		{
		case SYNT_ERR:
			cout<<"�﷨���������˵����\n"<<endl;
			break;
		case IN_SPACE:
			cout<<"����֮�䲻�����пո�\n"<<endl;
			break;
		case DIV_BY_0:
			cout<<"��������Ϊ�㣡\n"<<endl;
			break;
		case RNG_ERR:
			errno=0;
			cout<<"������̫��\n"<<endl;
			break;
		case DOM_ERR:
			errno=0;
			cout<<"ĳ���������Ա����Ƿ���\n"<<endl;
			break;
		case SYMB_ERR:
			cout<<"���ʽ���зǷ��ַ���\n"<<endl;
			break;
		}
	}
}

#if 0

#include "calc.h"
#include <iostream>

using namespace std;

int main()
{
	AmaF_Calc calculator;
	string exp;

	cout<<"////AmaranthF�ļ�����////"<<'\n'<<endl;
	calculator.help();

	while(1)
	{
		cout<<"��������ʽ��";

		char str[150];
		cin.getline(str,150);
		exp=str;

		if(exp.compare ("exit")==0)
		{
			cout<<"��л����ʹ�ã�"<<endl;
			break;
		}
		else if(exp.compare ("help")==0)
		{
			calculator.help();
			continue;
		}

		calculator.evalExpression(exp);
	}

	return 0;
}
#endif