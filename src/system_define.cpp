#include "system_head.h"
#include <cstring>
# author：向鹏
using namespace std;

//检查输入的名字是否合法，返回true为合法
bool check_name(char *str)
{
    char a;
    int b=strlen(str);
    if(b<4||b>10)
    {
        cout<<"必须为2到5个汉字"<<endl;
        return false;
    }
    for(int i=0;i<strlen(str);i++)
    {
        a=str[i];
        if(a>=0&&a<=127)
            return false;
    }
    return true;
}

//检查输入的准考证号是否合法，返回true为合法
bool check_exam_num(char *str)
{
    if(strlen(str)!=14)
    {
        cout<<"(长度不符！！)"<<endl;;
        return false;
    }
    for(int i=0;str[i]!='\0';i++)
    {
        if(str[i]<'0'||str[i]>'9')
        {
            cout<<"(准考证号只可能是纯数字！！)"<<endl;
            return false;
        }
    }
    return true;
}

//构造函数
//功能：将has_id_num,has_sex,has_birthday初始化为false
student::student()
{
    has_exam_num=has_name=has_sex=has_birthday=has_id_num=has_is_science=has_scores=0;
}

//输入准考证号
void student::set_exam_num(char str[])
{
    strcpy(exam_num,str);
}

//输入姓名
void student::set_name()
{
    cout<<"请输入中文姓名：";
    char str[41];
loop1:
    gets(str);
    if(has_name&&str[0]=='\0')
    {
        cout<<"(提示：没修改)"<<endl;
        return ;
    }
    if(has_name==false&&str[0]=='\0')
    {
        cout<<"  该姓名必须输入！！\n请输入中文姓名：";
        goto loop1;
    }
    if( check_name(str) )
    {
        strcpy(name,str);
    }
    else
    {
        cout<<"输入名字不合法！请重新输入（中文）：";
        goto loop1;
    }
}

//输入性别
//      修改时判断与身份证上的性别是否符合
void student::set_sex( )
{

    cout<<"选择你的性别：  0.女  1.男"<<endl;
    cout<<"请选择：";
    char str[3];
    char i;
loop2:
    gets(str);
    if(has_sex&&str[0]=='\0')
    {
        cout<<"(提示：没修改)"<<endl;
        return ;
    }
    if(has_sex==false&&str[0]=='\0')
    {
        cout<<"(提示：此项为必填项！！)\n请选择：";
        goto loop2;
    }
    if(strlen(str)>1)
    {
        cout<<"请输入正确的选项！！重新选择：";
        goto loop2;
    }
    i=str[0]-48;
    if(0<=i&&i<=1)
    {
        sex=i;
    }
    else
    {
        cout<<"请输入正确的选项！！重新选择：";
        goto loop2;
    }
    if(has_id_num==true&&id_num.sex!=sex)
    {
        cout<<"  性别与身份证上所显示的有差异！！"<<endl;
        cout<<"是否重新选择性别？(Y/N)   ";
        char ch[4];
loop2_1:
        gets(ch);
        if(strlen(ch)>1)
        {
            cout<<  "输入错误！是否重新输入出生日期？(Y/N)   ";
            goto loop2_1;
        }
        if(ch[0]=='Y'||ch[0]=='y')
        {
            cout<<"请重新输入出生日期：";
            goto loop2;
        }
        else if(ch[0]!='N'&&ch[0]!='n')
        {
            cout<<  "输入错误！是否重新输入出生日期？(Y/N)   ";
            goto loop2_1;
        }
    }
    if(sex)
        strcpy(Sex,"男");
    else
        strcpy(Sex,"女");
    has_sex=true;
}

//输入出生日期
//功能：用到自定义Date类对输入日期进行合法性检查
//      修改时判断与身份证上的出生日期是否符合
void student::set_birthday( )
{
    cout<<"请输入出生日期(年月日分别以一个空格分开)：";
loop4:
    cin>>birthday;
    if(has_birthday&&birthday.year==-1)
    {
        cout<<"(提示：没修改)"<<endl;
        return ;
    }
    if(has_birthday==false&&birthday.year==-1)
    {
        cout<<"(提示：此项为必填项！！)\n请输入出生日期：";
        goto loop4;
    }
    if( (2017-birthday.year)<=3 || (2017-birthday.year>=100) )
    {
        cout<<"别开玩笑了，赶紧输入正确的出生日期吧~(3<年龄<100)"<<endl;
        cout<<"请重新输入出生日期：";
        goto loop4;
    }
    if(has_id_num==true&& (id_num.year!=birthday.year||id_num.month!=birthday.month||id_num.day!=birthday.day) )
    {
        cout<<"  出生日期与身份证上所显示的有差异！！"<<endl;
        cout<<"是否重新输入出生日期？(Y/N)   ";
        char ch[4];
loop4_1:
        gets(ch);
        if(strlen(ch)>1)
        {
            cout<<  "输入错误！是否重新输入出生日期？(Y/N)   ";
            goto loop4_1;
        }
        if(ch[0]=='Y'||ch[0]=='y')
        {
            cout<<"请重新输入出生日期：";
            goto loop4;
        }
        else if(ch[0]!='N'&&ch[0]!='n')
        {
            cout<<  "输入错误！是否重新输入出生日期？(Y/N)   ";
            goto loop4_1;
        }
    }
    has_birthday=true;
}

//输入身份证号码
//功能：检查身份证上的出生日期和性别是否与前面输入一致
//      检查最后一位校验码是否合法
//      用到自定义ID类进行输入检查(包含行政区划)
void student::set_id_num()
{
    cout<<"请输入身份证号码(可不填)：";
loop5:
    cin>>id_num;
    if(has_id_num&&id_num.year==-1)
    {
        cout<<"(提示：没修改)"<<endl;
        return ;
    }
    if(has_id_num==false&&id_num.year==-1)
    {
        cout<<"(提示：未输入)"<<endl;
        return;
    }
    if(id_num.lastnum!=id_num.right_lastnum)
    {
        cout<<"  校验码错误！";
        cout<<"请重新输入身份证号码：";
        goto loop5;
    }
    if(has_birthday==true && (id_num.year!=birthday.year||id_num.month!=birthday.month||id_num.day!=birthday.day) )
    {
        cout<<"  身份证与前面所确定的出生日期有差异！！"<<endl;
        cout<<"是否修改出生日期？(Y/N)   ";
        char ch[4];
loop5_2:
        gets(ch);
        if(strlen(ch)>1)
        {
            cout<<  "输入错误！是否修改出生日期？(Y/N)   ";
            goto loop5_2;
        }
        if(ch[0]=='Y'||ch[0]=='y')
        {
            birthday.year=id_num.year;
            birthday.month=id_num.month;
            birthday.day=id_num.day;
            cout<<"修改成功！"<<endl;
        }
        else if(ch[0]=='N'||ch[0]=='n')
        {
            cout<<"请重新输入身份证号码：";
            goto loop5;
        }
        else
        {
            cout<<  "输入错误！是否修改出生日期？(Y/N)   ";
            goto loop5_2;
        }
    }
    if(has_sex==true&&id_num.sex!=sex)
    {
        cout<<"  身份证与前面所确定的性别有差异！！"<<endl;
        cout<<"是否修改性别？(Y/N)   ";
        char ch[4];
loop5_3:
        gets(ch);
        if(strlen(ch)>1)
        {
            cout<<  "输入错误！是否修改性别？(Y/N)   ";
            goto loop5_3;
        }
        if(ch[0]=='Y'||ch[0]=='y')
        {
            sex=!sex;
            cout<<"修改成功！"<<endl;
        }
        else if(ch[0]=='N'||ch[0]=='n')
        {
            cout<<"请重新输入身份证号码：";
            goto loop5;
        }
        else
        {
            cout<<  "输入错误！是否修改性别？(Y/N)   ";
            goto loop5_3;
        }
    }
    has_id_num=true;
}

//选择文理科
void student::set_is_science( )
{

    cout<<"选择你的类别：  0.文科  1.理科"<<endl;
    cout<<"请选择：";
    char str[3];
    char i;
loop6:
    gets(str);
    if(has_is_science&&str[0]=='\0')
    {
        cout<<"(提示：没修改)"<<endl;
        return ;
    }
    if(has_is_science==false&&str[0]=='\0')
    {
        cout<<"(提示：此项为必填项！！)\n请选择：";
        goto loop6;
    }
    if(strlen(str)>1)
    {
        cout<<"请输入正确的选项！！重新选择：";
        goto loop6;
    }
    i=str[0]-48;
    if(0<=i&&i<=1)
    {
        is_science=i;
    }
    else
    {
        cout<<"请输入正确的选项！！重新选择：";
        goto loop6;
    }
    if(is_science)
        strcpy(subject,"理综");
    else
        strcpy(subject,"文综");
}

//输入考试成绩并简单判断输入
void student::set_scores( )
{
    char str[7];
loop7_0:
    do
    {
        scores[0]=0;
        cout<<"请输入语文成绩(0-150)：";
        gets(str);
        if(has_scores&&str[0]=='\0')
        {
            cout<<"(提示：没修改)"<<endl;
            goto loop7_1 ;
        }
        if(str[0]=='\0')
        {
            cout<<"(提示：此项为必填项！！)"<<endl;
            goto loop7_0;
        }
        for(int i=0;str[i]!='\0';i++)
            scores[0]=scores[0]*10+str[i]-48;
        if(scores[0]>=0&&scores[0]<=150)
            break;
        else cout<<"    语文成绩输入错误！！请重新输入"<<endl;
    }while(1);
loop7_1:
    do
    {
        scores[1]=0;
        cout<<"请输入数学成绩(0-150)：";
        gets(str);
        if(has_scores&&str[0]=='\0')
        {
            cout<<"(提示：没修改)"<<endl;
            goto loop7_2 ;
        }
        if(str[0]=='\0')
        {
            cout<<"(提示：此项为必填项！！)"<<endl;
            goto loop7_1;
        }
        for(int i=0;str[i]!='\0';i++)
            scores[1]=scores[1]*10+str[i]-48;
        if(scores[1]>=0&&scores[1]<=150)
            break;
        else cout<<"    数学成绩输入错误！！请重新输入"<<endl;
    }while(1);
loop7_2:
    do
    {
        scores[2]=0;
        cout<<"请输入英语成绩(0-150)：";
        gets(str);
        if(has_scores&&str[0]=='\0')
        {
            cout<<"(提示：没修改)"<<endl;
            goto loop7_3 ;
        }
        if(str[0]=='\0')
        {
            cout<<"(提示：此项为必填项！！)"<<endl;
            goto loop7_2;
        }
        for(int i=0;str[i]!='\0';i++)
            scores[2]=scores[2]*10+str[i]-48;
        if(scores[2]>=0&&scores[2]<=150)
            break;
        else cout<<"    英语成绩输入错误！！请重新输入"<<endl;
    }while(1);
loop7_3:
    do
    {
        scores[3]=0;
        cout<<"请输入"<<subject<<"成绩(0-300)：";
        gets(str);
        if(has_scores&&str[0]=='\0')
        {
            cout<<"(提示：没修改)"<<endl;
            return ;
        }
        if(str[0]=='\0')
        {
            cout<<"(提示：此项为必填项！！)"<<endl;
            goto loop7_3;
        }
        for(int i=0;str[i]!='\0';i++)
            scores[3]=scores[3]*10+str[i]-48;
        if(scores[3]>=0&&scores[3]<=300)
            break;
        else cout<<"    "<<subject<<"成绩输入错误！！请重新输入"<<endl;
    }while(1);
    sum_score=scores[0]+scores[1]+scores[2]+scores[3];
}

//输入所有信息
void student::set_all( char str[])
{
    set_exam_num(str);//输入准考证号
    set_name( );//输入姓名
    set_sex( );//选择性别
    set_birthday( );//输入出生日
    set_id_num( );//输入身份证号码
    set_is_science( );//选择文理科
    set_scores( );//输入考试成绩
}





