#include "ID_head.h"
#include <string.h>
#include <stdlib.h>
using namespace std;

char get_right_lastnum(char const *str)//根据身份证前17位数字求出最后一位校验码
{
    char a[19];
    strcpy(a,str);
    char last_num;
    int i,n,sum=0;
    for(i=0;i<17;i++)
        a[i]=a[i]-48;
    sum=a[0]*7+a[1]*9+a[2]*10+a[3]*5+a[4]*8+a[5]*4+a[6]*2+a[7]*1+a[8]*6+a[9]*3+a[10]*7+a[11]*9+a[12]*10+a[13]*5+a[14]*8+a[15]*4+a[16]*2;
    n=sum%11;
    if(n>2) last_num=(12-n)+48;
    if(n==0) last_num='1';
    if(n==1) last_num='0';
    if(n==2) last_num='X';
    return last_num;
}

int getCodePlaceTable( int a[])//将文件的区划存入数组a中并返回区划个数
{
    FILE* fp = fopen("IdentityCodePlace.txt", "r");
    if (fp == NULL) {
        fprintf(stderr,"\a（将不验证行政区）存放行政区划对照表的文件[%s]不存在！\n","IdentityCodePlace.txt");
        return -1;
    }
    int n=0;
    while (fscanf(fp,"%d",&a[n])==1)
        n++;
    fclose(fp);
    return n;
}

bool check_exist(int a[],int code,int n)//检查你输入的区划code是否在所有区划的a数组中
{
    int i;
    for(i=0;i<n;i++)
    {
        if(a[i]==code)
            return true;
    }
    return false;
}

void ID::set_id(char *str)
{
    strcpy(this->id_num,str);
}

bool ID::check_id(char const *str)
{
    if(strlen(str)!=18)
    {
        cout<<"  长度不符合规定！";
        return false;
    }
    
    //下面确定输入身份证的年月日
    year=month=day=0;
    for(int i=6;i<10;i++)
    {
        year=year*10+str[i]-48;
    }
    month=str[10]-48;
    month=month*10+str[11]-48;
    day=str[12]-48;
    day=day*10+str[13]-48;
    //确定输入身份证的性别
    if(str[16]%2==0)
        sex=false;//女
    else
        sex=true;//男
    
    int a[3600];
    int n = getCodePlaceTable(a);//将文件的区划存入数组a中并返回区划个数

    if (n == -1) return true; //读文件出现问题，不判断行政区
    int code = 0;
    for (int i = 0; i < 6; i++)//取身份证前六位变成int
    {
        code = code * 10 + str[i] - 48;
    }
    if (check_exist(a, code, n) == false)
    {
        cout << "  行政区划错误！";
        return false;
    }
    return true;
}

ID &ID::operator=( ID &id)//重载赋值运算符
{
    strcpy(id_num,id.id_num);
    year=id.year, month=id.month, day=id.day;
    lastnum=id.lastnum;
    right_lastnum=id.right_lastnum;
    sex=id.sex;
    return *this;
}

bool ID::operator==( const ID &id)//重载==运算符
{
    if(strcmp(id_num,id.id_num)==0)
        return true;
    else
        return false;
}

istream &operator>>(istream &in,ID &id)
{
    char str[19];
loop5_1:
    gets(str);
    if(str[0]=='\0')
        return in;
    if(strcmp(str,"0")==0)
    {
        id.year=0;
        return in;
    }
    if( id.check_id(str) )
    {
        id.set_id(str);
    }
    else
    {
        cout<<"请重新输入身份证号码：";
        goto loop5_1;
    }
    id.lastnum=str[17];
    id.right_lastnum=get_right_lastnum(str);
    return in;
}

ostream &operator<<(ostream &out,ID &id)
{
    cout<<id.id_num;
    return out;
}











