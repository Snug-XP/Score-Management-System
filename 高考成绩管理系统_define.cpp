#include "�߿��ɼ�����ϵͳ_head.h"
#include <cstring>
using namespace std;

//�������������Ƿ�Ϸ�������trueΪ�Ϸ�
bool check_name(char *str)
{
    char a;
    int b=strlen(str);
    if(b<4||b>10)
    {
        cout<<"����Ϊ2��5������"<<endl;
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

//��������׼��֤���Ƿ�Ϸ�������trueΪ�Ϸ�
bool check_exam_num(char *str)
{
    if(strlen(str)!=14)
    {
        cout<<"(���Ȳ�������)"<<endl;;
        return false;
    }
    for(int i=0;str[i]!='\0';i++)
    {
        if(str[i]<'0'||str[i]>'9')
        {
            cout<<"(׼��֤��ֻ�����Ǵ����֣���)"<<endl;
            return false;
        }
    }
    return true;
}

//���캯��
//���ܣ���has_id_num,has_sex,has_birthday��ʼ��Ϊfalse
student::student()
{
    has_exam_num=has_name=has_sex=has_birthday=has_id_num=has_is_science=has_scores=0;
}

//����׼��֤��
void student::set_exam_num(char str[])
{
    strcpy_s(exam_num,str);
}

//��������
void student::set_name()
{
    cout<<"����������������";
    char str[41];
loop1:
    gets_s(str);
    if(has_name&&str[0]=='\0')
    {
        cout<<"(��ʾ��û�޸�)"<<endl;
        return ;
    }
    if(has_name==false&&str[0]=='\0')
    {
        cout<<"  �������������룡��\n����������������";
        goto loop1;
    }
    if( check_name(str) )
    {
        strcpy_s(name,str);
    }
    else
    {
        cout<<"�������ֲ��Ϸ������������루���ģ���";
        goto loop1;
    }
}

//�����Ա�
//      �޸�ʱ�ж������֤�ϵ��Ա��Ƿ����
void student::set_sex( )
{

    cout<<"ѡ������Ա�  0.Ů  1.��"<<endl;
    cout<<"��ѡ��";
    char str[3];
    char i;
loop2:
    gets_s(str);
    if(has_sex&&str[0]=='\0')
    {
        cout<<"(��ʾ��û�޸�)"<<endl;
        return ;
    }
    if(has_sex==false&&str[0]=='\0')
    {
        cout<<"(��ʾ������Ϊ�������)\n��ѡ��";
        goto loop2;
    }
    if(strlen(str)>1)
    {
        cout<<"��������ȷ��ѡ�������ѡ��";
        goto loop2;
    }
    i=str[0]-48;
    if(0<=i&&i<=1)
    {
        sex=i;
    }
    else
    {
        cout<<"��������ȷ��ѡ�������ѡ��";
        goto loop2;
    }
    if(has_id_num==true&&id_num.sex!=sex)
    {
        cout<<"  �Ա������֤������ʾ���в��죡��"<<endl;
        cout<<"�Ƿ�����ѡ���Ա�(Y/N)   ";
        char ch[4];
loop2_1:
        gets_s(ch);
        if(strlen(ch)>1)
        {
            cout<<  "��������Ƿ���������������ڣ�(Y/N)   ";
            goto loop2_1;
        }
        if(ch[0]=='Y'||ch[0]=='y')
        {
            cout<<"����������������ڣ�";
            goto loop2;
        }
        else if(ch[0]!='N'&&ch[0]!='n')
        {
            cout<<  "��������Ƿ���������������ڣ�(Y/N)   ";
            goto loop2_1;
        }
    }
    if(sex)
        strcpy_s(Sex,"��");
    else
        strcpy_s(Sex,"Ů");
    has_sex=true;
}

//�����������
//���ܣ��õ��Զ���Date����������ڽ��кϷ��Լ��
//      �޸�ʱ�ж������֤�ϵĳ��������Ƿ����
void student::set_birthday( )
{
    cout<<"�������������(�����շֱ���һ���ո�ֿ�)��";
loop4:
    cin>>birthday;
    if(has_birthday&&birthday.year==-1)
    {
        cout<<"(��ʾ��û�޸�)"<<endl;
        return ;
    }
    if(has_birthday==false&&birthday.year==-1)
    {
        cout<<"(��ʾ������Ϊ�������)\n������������ڣ�";
        goto loop4;
    }
    if( (2017-birthday.year)<=3 || (2017-birthday.year>=100) )
    {
        cout<<"����Ц�ˣ��Ͻ�������ȷ�ĳ������ڰ�~(3<����<100)"<<endl;
        cout<<"����������������ڣ�";
        goto loop4;
    }
    if(has_id_num==true&& (id_num.year!=birthday.year||id_num.month!=birthday.month||id_num.day!=birthday.day) )
    {
        cout<<"  �������������֤������ʾ���в��죡��"<<endl;
        cout<<"�Ƿ���������������ڣ�(Y/N)   ";
        char ch[4];
loop4_1:
        gets_s(ch);
        if(strlen(ch)>1)
        {
            cout<<  "��������Ƿ���������������ڣ�(Y/N)   ";
            goto loop4_1;
        }
        if(ch[0]=='Y'||ch[0]=='y')
        {
            cout<<"����������������ڣ�";
            goto loop4;
        }
        else if(ch[0]!='N'&&ch[0]!='n')
        {
            cout<<  "��������Ƿ���������������ڣ�(Y/N)   ";
            goto loop4_1;
        }
    }
    has_birthday=true;
}

//�������֤����
//���ܣ�������֤�ϵĳ������ں��Ա��Ƿ���ǰ������һ��
//      ������һλУ�����Ƿ�Ϸ�
//      �õ��Զ���ID�����������(������������)
void student::set_id_num()
{
    cout<<"���������֤����(�ɲ���)��";
loop5:
    cin>>id_num;
    if(has_id_num&&id_num.year==-1)
    {
        cout<<"(��ʾ��û�޸�)"<<endl;
        return ;
    }
    if(has_id_num==false&&id_num.year==-1)
    {
        cout<<"(��ʾ��δ����)"<<endl;
        return;
    }
    if(id_num.lastnum!=id_num.right_lastnum)
    {
        cout<<"  У�������";
        cout<<"�������������֤���룺";
        goto loop5;
    }
    if(has_birthday==true && (id_num.year!=birthday.year||id_num.month!=birthday.month||id_num.day!=birthday.day) )
    {
        cout<<"  ���֤��ǰ����ȷ���ĳ��������в��죡��"<<endl;
        cout<<"�Ƿ��޸ĳ������ڣ�(Y/N)   ";
        char ch[4];
loop5_2:
        gets_s(ch);
        if(strlen(ch)>1)
        {
            cout<<  "��������Ƿ��޸ĳ������ڣ�(Y/N)   ";
            goto loop5_2;
        }
        if(ch[0]=='Y'||ch[0]=='y')
        {
            birthday.year=id_num.year;
            birthday.month=id_num.month;
            birthday.day=id_num.day;
            cout<<"�޸ĳɹ���"<<endl;
        }
        else if(ch[0]=='N'||ch[0]=='n')
        {
            cout<<"�������������֤���룺";
            goto loop5;
        }
        else
        {
            cout<<  "��������Ƿ��޸ĳ������ڣ�(Y/N)   ";
            goto loop5_2;
        }
    }
    if(has_sex==true&&id_num.sex!=sex)
    {
        cout<<"  ���֤��ǰ����ȷ�����Ա��в��죡��"<<endl;
        cout<<"�Ƿ��޸��Ա�(Y/N)   ";
        char ch[4];
loop5_3:
        gets_s(ch);
        if(strlen(ch)>1)
        {
            cout<<  "��������Ƿ��޸��Ա�(Y/N)   ";
            goto loop5_3;
        }
        if(ch[0]=='Y'||ch[0]=='y')
        {
            sex=!sex;
            cout<<"�޸ĳɹ���"<<endl;
        }
        else if(ch[0]=='N'||ch[0]=='n')
        {
            cout<<"�������������֤���룺";
            goto loop5;
        }
        else
        {
            cout<<  "��������Ƿ��޸��Ա�(Y/N)   ";
            goto loop5_3;
        }
    }
    has_id_num=true;
}

//ѡ�������
void student::set_is_science( )
{

    cout<<"ѡ��������  0.�Ŀ�  1.���"<<endl;
    cout<<"��ѡ��";
    char str[3];
    char i;
loop6:
    gets_s(str);
    if(has_is_science&&str[0]=='\0')
    {
        cout<<"(��ʾ��û�޸�)"<<endl;
        return ;
    }
    if(has_is_science==false&&str[0]=='\0')
    {
        cout<<"(��ʾ������Ϊ�������)\n��ѡ��";
        goto loop6;
    }
    if(strlen(str)>1)
    {
        cout<<"��������ȷ��ѡ�������ѡ��";
        goto loop6;
    }
    i=str[0]-48;
    if(0<=i&&i<=1)
    {
        is_science=i;
    }
    else
    {
        cout<<"��������ȷ��ѡ�������ѡ��";
        goto loop6;
    }
    if(is_science)
        strcpy_s(subject,"����");
    else
        strcpy_s(subject,"����");
}

//���뿼�Գɼ������ж�����
void student::set_scores( )
{
    char str[7];
loop7_0:
    do
    {
        scores[0]=0;
        cout<<"���������ĳɼ�(0-150)��";
        gets_s(str);
        if(has_scores&&str[0]=='\0')
        {
            cout<<"(��ʾ��û�޸�)"<<endl;
            goto loop7_1 ;
        }
        if(str[0]=='\0')
        {
            cout<<"(��ʾ������Ϊ�������)"<<endl;
            goto loop7_0;
        }
        for(int i=0;str[i]!='\0';i++)
            scores[0]=scores[0]*10+str[i]-48;
        if(scores[0]>=0&&scores[0]<=150)
            break;
        else cout<<"    ���ĳɼ�������󣡣�����������"<<endl;
    }while(1);
loop7_1:
    do
    {
        scores[1]=0;
        cout<<"��������ѧ�ɼ�(0-150)��";
        gets_s(str);
        if(has_scores&&str[0]=='\0')
        {
            cout<<"(��ʾ��û�޸�)"<<endl;
            goto loop7_2 ;
        }
        if(str[0]=='\0')
        {
            cout<<"(��ʾ������Ϊ�������)"<<endl;
            goto loop7_1;
        }
        for(int i=0;str[i]!='\0';i++)
            scores[1]=scores[1]*10+str[i]-48;
        if(scores[1]>=0&&scores[1]<=150)
            break;
        else cout<<"    ��ѧ�ɼ�������󣡣�����������"<<endl;
    }while(1);
loop7_2:
    do
    {
        scores[2]=0;
        cout<<"������Ӣ��ɼ�(0-150)��";
        gets_s(str);
        if(has_scores&&str[0]=='\0')
        {
            cout<<"(��ʾ��û�޸�)"<<endl;
            goto loop7_3 ;
        }
        if(str[0]=='\0')
        {
            cout<<"(��ʾ������Ϊ�������)"<<endl;
            goto loop7_2;
        }
        for(int i=0;str[i]!='\0';i++)
            scores[2]=scores[2]*10+str[i]-48;
        if(scores[2]>=0&&scores[2]<=150)
            break;
        else cout<<"    Ӣ��ɼ�������󣡣�����������"<<endl;
    }while(1);
loop7_3:
    do
    {
        scores[3]=0;
        cout<<"������"<<subject<<"�ɼ�(0-300)��";
        gets_s(str);
        if(has_scores&&str[0]=='\0')
        {
            cout<<"(��ʾ��û�޸�)"<<endl;
            return ;
        }
        if(str[0]=='\0')
        {
            cout<<"(��ʾ������Ϊ�������)"<<endl;
            goto loop7_3;
        }
        for(int i=0;str[i]!='\0';i++)
            scores[3]=scores[3]*10+str[i]-48;
        if(scores[3]>=0&&scores[3]<=300)
            break;
        else cout<<"    "<<subject<<"�ɼ�������󣡣�����������"<<endl;
    }while(1);
    sum_score=scores[0]+scores[1]+scores[2]+scores[3];
}

//����������Ϣ
void student::set_all( char str[])
{
    set_exam_num(str);//����׼��֤��
    set_name( );//��������
    set_sex( );//ѡ���Ա�
    set_birthday( );//���������
    set_id_num( );//�������֤����
    set_is_science( );//ѡ�������
    set_scores( );//���뿼�Գɼ�
}





