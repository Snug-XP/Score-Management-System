#include "Date_head.h"
#include <string.h>
using namespace std;
bool judge ( int year,int month,int day )//�ж������Ƿ�Ϸ�,����1Ϊ�Ƿ�����
{
	if(month>12||month<1) {
		cout<<"�����������"<<endl<<"���������룺"; return true;}
	else if(day>31||day<1) {
		cout<<"�����������"<<endl<<"���������룺"; return true;}
	else if(year>9999||year<1) {
		cout<<"�����������"<<endl<<"���������룺"; return true;}
	else if((month==2||month==4||month==6||month==9||month==11)&&day==31) {
		cout<<"�����������"<<endl<<"���������룺"; return true;}
	else if(month==2&&day==30) {
		cout<<"����2�µ������������"<<endl<<"���������룺"; return true;}
	else if(month==2&&day==29)
	{
		if(year%4==0&&year%100!=0||year%400==0) return false;
		else {
			cout<<"����2�µ���������������������룺"; return true;}
	}
	else  return false;
}
////////////////////////////////////////////////////////////////
bool easy_check(char *p)//���ж������Ƿ�Ϸ�������1Ϊ�Ƿ�
{
	int n=0;//���ո����
	if(strlen(p)>10){
		cout<<"���볤����������"<<endl<<"���������룺";
		return true;
	}
	for(int i=0;i<strlen(p);i++){
		if(p[i]!=' '&&( p[i]<'0'||p[i]>'9' )){
			cout<<"���������ֻ�ո񣬲�Ҫ���������ַ���"<<endl<<"���������룺";
			return true;
		}
		if(p[i]==' ')  n++;
	}
	if (n!=2) {
		cout<<"�������"<<endl<<"���������룺";
		return true;
	}

	return false;
}
/////////////////////////////////////////////////////////////////////////|��ʼ����������|

Date::Date()
{
	year=month=day=-1;//������
	for(int i=0;i<13;i++){
		if(i==0||i==1||i==3||i==5||i==7||i==8||i==10||i==12)
			Mon_day[i]=31;
		else Mon_day[i]=30;
		Mon_day[2]=28;
	}
}

void Date::judge_February()//�ж����꣬��Ϊ���꣬�Ѷ������������Ϊ29
{
	if(year%4==0&&year%100!=0||year%400==0)
		Mon_day[2]=29;
	else Mon_day[2]=28;
}

void Date::EditDate ()                //����(�򸲸�)���ж�����
{
	char str[20];
loop1:  gets(str);
		if(str[0]=='\0')
		{
			return;
		}
		while( easy_check(str) ){
			goto loop1;
		}
		year=month=day=0;
		int i;
		for (i=0;str[i] != ' ';i++)//��str�е���ת��������
		{
			year=year*10+str[i]-48;
		}
		for (i++;str[i] != ' ';i++)//��str�е���ת��������
		{
			month=month*10+str[i]-48;
		}
		for (i++;i<strlen(str);i++)//��str�е���ת��������
		{
			day=day*10+str[i]-48;
		}
		while ( judge(year,month,day) ){
			goto loop1;
		}
		judge_February();
}

Date &Date::operator=(Date &d )                    //���ظ�ֵ�����
{
    year=d.day;
    month=d.month;
    day=d.day;
    for(int i=0;i<13;i++)
    {
        Mon_day[i]=d.Mon_day[i];
    }
    return *this;
}

istream &operator>>(istream &in ,Date &d )//�������������
{
	d.EditDate();
	return in;
}

ostream &operator<<(ostream &out ,Date &d )//������������
{
    cout<<d.year<<"��"<<d.month<<"��"<<d.day<<"��";
	return out;
}




