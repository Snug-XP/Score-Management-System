#include <stdio.h>
#include <iostream>
# author������
bool judge ( int ,int , int );  //�ж������Ƿ�Ϸ�,����1Ϊ�Ƿ�����
bool easy_check ( char );       //���ж������Ƿ�Ϸ�������1Ϊ�Ƿ�
class Date{
	int Mon_day[13];  //ÿ�µ�����
public:
	int year,month,day;
	Date();
	void judge_February(); //�ж����꣬��Ϊ���꣬�Ѷ������������Ϊ29
	void EditDate ();                           //����(�򸲸�)���ж�����
	Date &operator=(Date &);                    //���ظ�ֵ�����
	friend std::istream &operator>>(std::istream & ,Date & );//�������������
	friend std::ostream &operator<<(std::ostream & ,Date & );//������������

};
