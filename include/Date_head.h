#include <stdio.h>
#include <iostream>
# author：向鹏
bool judge ( int ,int , int );  //判断日期是否合法,返回1为非法日期
bool easy_check ( char );       //简单判断输入是否合法，返回1为非法
class Date{
	int Mon_day[13];  //每月的天数
public:
	int year,month,day;
	Date();
	void judge_February(); //判断闰年，若为闰年，把二月最大天数改为29
	void EditDate ();                           //输入(或覆盖)并判断数据
	Date &operator=(Date &);                    //重载赋值运算符
	friend std::istream &operator>>(std::istream & ,Date & );//重载输入运算符
	friend std::ostream &operator<<(std::ostream & ,Date & );//重载输出运算符

};
