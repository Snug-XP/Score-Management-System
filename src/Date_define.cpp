#include "Date_head.h"
#include <string.h>
using namespace std;
bool judge ( int year,int month,int day )//判断日期是否合法,返回1为非法日期
{
	if(month>12||month<1) {
		cout<<"月数输入错误！"<<endl<<"请重新输入："; return true;}
	else if(day>31||day<1) {
		cout<<"日数输入错误！"<<endl<<"请重新输入："; return true;}
	else if(year>9999||year<1) {
		cout<<"年数输入错误！"<<endl<<"请重新输入："; return true;}
	else if((month==2||month==4||month==6||month==9||month==11)&&day==31) {
		cout<<"日数输入错误！"<<endl<<"请重新输入："; return true;}
	else if(month==2&&day==30) {
		cout<<"该年2月的日数输入错误！"<<endl<<"请重新输入："; return true;}
	else if(month==2&&day==29)
	{
		if(year%4==0&&year%100!=0||year%400==0) return false;
		else {
			cout<<"该年2月的日数输入错误！请重新输入："; return true;}
	}
	else  return false;
}
////////////////////////////////////////////////////////////////
bool easy_check(char *p)//简单判断输入是否合法，返回1为非法
{
	int n=0;//检查空格个数
	if(strlen(p)>10){
		cout<<"输入长度明显有误！"<<endl<<"请重新输入：";
		return true;
	}
	for(int i=0;i<strlen(p);i++){
		if(p[i]!=' '&&( p[i]<'0'||p[i]>'9' )){
			cout<<"请输入数字或空格，不要输入其它字符！"<<endl<<"请重新输入：";
			return true;
		}
		if(p[i]==' ')  n++;
	}
	if (n!=2) {
		cout<<"输入错误！"<<endl<<"请重新输入：";
		return true;
	}

	return false;
}
/////////////////////////////////////////////////////////////////////////|开始建立日期类|

Date::Date()
{
	year=month=day=-1;//空日期
	for(int i=0;i<13;i++){
		if(i==0||i==1||i==3||i==5||i==7||i==8||i==10||i==12)
			Mon_day[i]=31;
		else Mon_day[i]=30;
		Mon_day[2]=28;
	}
}

void Date::judge_February()//判断闰年，若为闰年，把二月最大天数改为29
{
	if(year%4==0&&year%100!=0||year%400==0)
		Mon_day[2]=29;
	else Mon_day[2]=28;
}

void Date::EditDate ()                //输入(或覆盖)并判断数据
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
		for (i=0;str[i] != ' ';i++)//把str中的年转换成数字
		{
			year=year*10+str[i]-48;
		}
		for (i++;str[i] != ' ';i++)//把str中的月转换成数字
		{
			month=month*10+str[i]-48;
		}
		for (i++;i<strlen(str);i++)//把str中的日转换成数字
		{
			day=day*10+str[i]-48;
		}
		while ( judge(year,month,day) ){
			goto loop1;
		}
		judge_February();
}

Date &Date::operator=(Date &d )                    //重载赋值运算符
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

istream &operator>>(istream &in ,Date &d )//重载输入运算符
{
	d.EditDate();
	return in;
}

ostream &operator<<(ostream &out ,Date &d )//重载输出运算符
{
    cout<<d.year<<"年"<<d.month<<"月"<<d.day<<"日";
	return out;
}




