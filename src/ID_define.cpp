#include "ID_head.h"
#include <string.h>
#include <stdlib.h>
using namespace std;

char get_right_lastnum(char const *str)//�������֤ǰ17λ����������һλУ����
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

int getCodePlaceTable( int a[])//���ļ���������������a�в�������������
{
    FILE* fp = fopen("IdentityCodePlace.txt", "r");
    if (fp == NULL) {
        fprintf(stderr,"\a��������֤����������������������ձ���ļ�[%s]�����ڣ�\n","IdentityCodePlace.txt");
        return -1;
    }
    int n=0;
    while (fscanf(fp,"%d",&a[n])==1)
        n++;
    fclose(fp);
    return n;
}

bool check_exist(int a[],int code,int n)//��������������code�Ƿ�������������a������
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
        cout<<"  ���Ȳ����Ϲ涨��";
        return false;
    }
    
    //����ȷ���������֤��������
    year=month=day=0;
    for(int i=6;i<10;i++)
    {
        year=year*10+str[i]-48;
    }
    month=str[10]-48;
    month=month*10+str[11]-48;
    day=str[12]-48;
    day=day*10+str[13]-48;
    //ȷ���������֤���Ա�
    if(str[16]%2==0)
        sex=false;//Ů
    else
        sex=true;//��
    
    int a[3600];
    int n = getCodePlaceTable(a);//���ļ���������������a�в�������������

    if (n == -1) return true; //���ļ��������⣬���ж�������
    int code = 0;
    for (int i = 0; i < 6; i++)//ȡ���֤ǰ��λ���int
    {
        code = code * 10 + str[i] - 48;
    }
    if (check_exist(a, code, n) == false)
    {
        cout << "  ������������";
        return false;
    }
    return true;
}

ID &ID::operator=( ID &id)//���ظ�ֵ�����
{
    strcpy(id_num,id.id_num);
    year=id.year, month=id.month, day=id.day;
    lastnum=id.lastnum;
    right_lastnum=id.right_lastnum;
    sex=id.sex;
    return *this;
}

bool ID::operator==( const ID &id)//����==�����
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
        cout<<"�������������֤���룺";
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











