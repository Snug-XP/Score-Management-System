#include "�߿��ɼ�����ϵͳ_head.h"
#include "OrderList_head.h"
#include <string.h>
#include <stdlib.h>

using namespace std;

//��ӡ���˵�ѡ��
void print_options()
{
	cout<<"    ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
	cout<<"    +                                                          +"<<endl;
	cout<<"    +                     �߿��ɼ�����ϵͳ                     +"<<endl;
	cout<<"    +                                                          +"<<endl;
	cout<<"    +                    1 --- ¼��ѧ����Ϣ                    +"<<endl;
	cout<<"    +                    2 --- �޸�ѧ����Ϣ                    +"<<endl;
	cout<<"    +                    3 --- ��ѯѧ���ɼ�                    +"<<endl;
	cout<<"    +                    4 --- ɾ��ѧ����Ϣ                    +"<<endl;
	cout<<"    +                    5 --- ���ѧ���ɼ�                    +"<<endl;
	cout<<"    +                    6 --- ͳ�������                      +"<<endl;
	cout<<"    +                    0 --- �˳�ϵͳ                        +"<<endl;
	cout<<"    +                                                          +"<<endl;
	cout<<"    ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n"<<endl;
}

//��ӡ�����˵�ѡ��
void print_search_options()
{
	cout<<"    ++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
	cout<<"    +                                                      +"<<endl;
	cout<<"    +                     ��ѯѧ����Ϣ                     +"<<endl;
	cout<<"    +                                                      +"<<endl;
	cout<<"    +                  1 --- ����׼��֤�Ų�ѯ              +"<<endl;
	cout<<"    +                  2 --- ����������ѯ                  +"<<endl;
	cout<<"    +                  3 --- �������֤�Ų�ѯ              +"<<endl;
	cout<<"    +                  0 --- �˳���ѯ                      +"<<endl;
	cout<<"    +                                                      +"<<endl;
	cout<<"    ++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n"<<endl;
}

//��ӡͳ��������˵�ѡ��
void print_analysis_options()
{
	cout<<"    +++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
	cout<<"    +                                                     +"<<endl;
	cout<<"    +                     ͳ�������                      +"<<endl;
	cout<<"    +                                                     +"<<endl;
	cout<<"    +                  1 --- ����ѧ��                     +"<<endl;
	cout<<"    +                  2 --- ���                         +"<<endl;
	cout<<"    +                  3 --- �Ŀ�                         +"<<endl;
	cout<<"    +                  4 --- ����                         +"<<endl;
	cout<<"    +                  5 --- Ů��                         +"<<endl;
	cout<<"    +                  0 --- �˳�                         +"<<endl;
	cout<<"    +                                                     +"<<endl;
	cout<<"    +++++++++++++++++++++++++++++++++++++++++++++++++++++++\n"<<endl;
}

//��ӡ�ɼ����棨����2��������
void put_one()
{
	cout<<"|   ׼��֤��   |   ����   | ���� | ��ѧ | Ӣ�� | ����/���� | �ܳɼ� | ���� |"<<endl;
	cout<<"|--------------|----------|------|------|------|-----------|--------|------|"<<endl;
}
void put_two(student *p)
{
	printf("|%5s|%6s(%s)|%5.1lf |%5.1lf |",p->get_exam_num(),p->get_name(),p->Sex,p->get_Chinese_score(),p->get_Math_score());
	printf("%5.1lf |%5.1lf(%s)|%6.1lf  |  %-4d|\n",p->get_Engliish_score(),p->get_Other_score(),p->subject,p->sum_score,p->ranking);
}

//���ȫ��ѧ���ɼ����ź���ģ�
void Look(student *p,int get_num)
{
	int i;
	if(get_num==0) {
		cout<<"    ��ǰϵͳ��û��ѧ�����ݣ�����¼�����ݣ�\n"<<endl;
		return;}
	put_one();
	for(i=0;i<get_num;i++)
	{
		put_two(p);
		p++;
	}
	cout<<"���س�������...";
	getchar();
}

//���ܳɼ�����
void Order(student *p,int get_num)
{
	int i,j;
	student *q;
	if(get_num==0) {
		return;}
	q=(student*)malloc(sizeof(student));
	for(i=get_num-1;i>0;i--)
    {
        for(j=0;j<i;j++)
		{
		    if(p[j].sum_score<p[j+1].sum_score)
			{
				*q=p[j];
				p[j]=p[j+1];
				p[j+1]=*q;
			}
		}
		p[i].ranking=i+1;
    }
    p[0].ranking=1;
    free(q);
}

//����¼��ѧ����Ϣ
//���أ�ѧ������
int set_information(student *p,int get_num)
{
	int i;
	char str[16];
	for(i=get_num;;i++)
	{
		cout<<"������ѧ����14λ׼��֤�ţ���׼��֤��Ϊ0����¼�룩��";
loop0:
        gets_s(str);
		if(strcmp(str,"0")==0)       return i;
        if(str[0]=='\0')
        {
            cout<<"(��ʾ������Ϊ�������)\n������׼��֤�ţ�";
            goto loop0;
        }
        if(check_exam_num(str))
        {
            p[i].set_exam_num(str);
        }
        else
        {
            cout<<"����׼��֤�Ų��Ϸ������������룺";
            goto loop0;
        }
		p[i].set_all(str);
	}
}

//�޸�ѧ����Ϣ
//���ܣ����ղ�ͬ�������������Ӧѧ����Ϣ
//      ��ѡ���޸�
void Update(student *p,const int get_num)
{
	if(get_num==0)
    {
		cout<<"    ��ǰϵͳ��û��ѧ�����ݣ�����¼�����ݣ�\n"<<endl;
		return;
    }
    char Right;

Update0:
    do
    {
        int counts[101],*q=counts;//���ڲ�ѯѧ����counts[0]������������������������ҵ������
        int choose;
        cout<<"    ����Ҫ�޸�����ѧ������Ϣ?"<<endl;
        q=Search(p,get_num,counts);
        if(q[0]==0)  goto Update3;
        if(q[0]==1)
        {
            choose=q[1];
            goto Update1_1;
        }
		do
        {
            choose=0;
			cout<<"��Ҫ�޸ĵ�������������¼����������������<";
			for(int i=1;i<q[0];i++)
                cout<<q[i]+1<<"��";//������������±��һ
            cout<<q[q[0]]+1<<">����";
            char str[4];
            gets_s(str);
            for(int i=0;str[i]!='\0';i++)
                choose=choose*10+str[i]-48;
            choose--;//�����������1��ɶ�Ӧ�������ڵ��±�
            for(int i=0;i<=q[0];i++)
            {
                if( (choose)==q[i])
                    goto Update1;
            }
            cout<<"    ������󣡣�����������"<<endl;
        }while(1);
Update1:
        put_one();
        put_two(p+choose);
Update1_1:
        do{
			cout<<"��Ҫ�޸ĸ�ѧ������Ϣ��(y/n)";
			scanf_s("%c",&Right);
			if(Right=='\n')
                goto Update1_1;
            else
                while(getchar()!='\n');
			if(Right!='y'&&Right!='n')
				cout<<"    �������"<<endl;
		}while(Right!='y'&&Right!='n');
		if(Right=='y')
		{
		    char str[16];
		    cout<<"������ѧ����14λ׼��֤�ţ�";
Update2:
		    gets_s(str);
		    if(strcmp(str,"0")==0)       return;
		    if(str[0]=='\0')
            {
                cout<<"(��ʾ������Ϊ�������)\n������׼��֤�ţ�";
        	    goto Update2;
            }
        	if(check_exam_num(str))
        	{
                p[choose].set_exam_num(str);
            }
            else
            {
                cout<<"����׼��֤�Ų��Ϸ������������룺";
                goto Update2;
            }
                p[choose].set_all(str);
        }
Update3:
        do
        {
            cout<<"�Ƿ�����޸�����ѧ����Ϣ��(y/n)";
            scanf_s("%c",&Right);
            if(Right=='\n')
                Right=0;
            else
                while(getchar()!='\n');
            if(Right!='y'&&Right!='n'&&Right!='\n')
                cout<<"    �������"<<endl;
        }while(Right!='y'&&Right!='n');
	}while(	Right=='y');
	cout<<"���س�������...";
	getchar();
}

//��ѯѧ����Ϣ
//���ܣ����ղ�ͬ�������������Ӧѧ����Ϣ����ӡ����
//���أ�Я����ѯ����ѧ����Ӧ�±��ָ��
int *Search(student *p,int get_num,int counts[])
{
    counts[0]=0;//counts[0]������������������������ҵ������
	int i,n;
	char Right,str[17];
	if(get_num==0) {
		cout<<"    ��ǰϵͳ��û��ѧ�����ݣ�����¼�����ݣ�\n"<<endl;
		return counts;}
search0:
	while(1)
    {
		print_search_options();
		cout<<"                         ������ѡ��(0-3):";
		scanf_s("%d",&n);
		while(getchar()!='\n');
        switch(n)
		{
		case 1 : goto search1;break;
		case 2 : goto search2;break;
		case 3 : goto search3;break;
		case 0 : return counts;
		default : cout<<"�����������������...\n"<<endl;
		}
	}
search1:
    do
    {
        counts[0]=0;//counts[0]������������������������ҵ������
		int find=0;
        cout<<"������Ҫ������ѧ����׼��֤�ţ�����0���أ���";
        gets_s(str);
		if(strcmp(str,"0")==0)       goto search0;
        if(str[0]=='\0')
        {
            goto search1;
        }
        if(check_exam_num(str)==false)
        {
            cout<<"����׼��֤�Ų��Ϸ������������룺"<<endl;
            goto search1;
        }
		for(i=0;i<get_num;i++)//ƥ���ѯ
		{
			if(strcmp(p[i].get_exam_num(),str)==0)
			{
				counts[0]++;
				counts[counts[0]]=i;
			}
		}
		if(counts[0]>0)
		{
		    cout<<"������"<<counts[0]<<"��ѧ��:"<<endl;
            put_one();
            for(int j=1;j<=counts[0];j++)//�������ƥ���ѧ����Ϣ
            {
                put_two(p+counts[j]);
            }
            return counts;
		}

        cout<<"    δ�ҷ���������ѧ������Ϣ!"<<endl;
		do{
			cout<<"�Ƿ������׼��֤������ѧ����Ϣ��(y/n)";
			scanf_s("%c",&Right);
			while(getchar()!='\n');
			if(Right!='y'&&Right!='n')
				cout<<"    �������"<<endl;
		}while(Right!='y'&&Right!='n');
	}while(Right=='y');
	goto search0;
search2:
    do
    {
        counts[0]=0;//counts[0]������������������������ҵ������
		int find=0;
        cout<<"������Ҫ������ѧ��������������0���أ���";
        gets_s(str);
		if(strcmp(str,"0")==0)       goto search0;
        if(str[0]=='\0')
        {
            goto search2;
        }
        if(check_name(str)==false)
        {
            cout<<"������������Ϸ������������룺";
            goto search2;
        }
		for(i=0;i<get_num;i++)//ƥ���ѯ
		{
			if(strcmp((p+i)->get_name(),str)==0)
			{
				counts[0]++;
				counts[counts[0]]=i;
			}
		}
		if(counts[0]>0)
		{
		    cout<<"������"<<counts[0]<<"��ѧ��:"<<endl;
            put_one();
            for(int j=1;j<=counts[0];j++)//�������ƥ���ѧ����Ϣ
            {
                put_two(p+counts[j]);
            }
            return counts;
		}
        cout<<"    δ�ҷ���������ѧ������Ϣ!"<<endl;
		do{
			cout<<"�Ƿ��������������ѧ����Ϣ��(y/n)";
			scanf_s("%c",&Right);
			while(getchar()!='\n');
			if(Right!='y'&&Right!='n')
				cout<<"    �������"<<endl;
		}while(Right!='y'&&Right!='n');
	}while(Right=='y');
	goto search0;
search3:
    do
    {
        counts[0]=0;//counts[0]������������������������ҵ������
		int find=0;
        cout<<"������Ҫ������ѧ�������֤���루����0���أ���";
        ID student_id;
        cin>>student_id;
        if(student_id.year==-1)     goto search3;
		if(student_id.year==0)       goto search0;
		for(i=0;i<get_num;i++)//ƥ���ѯ
		{
			if(student_id==p[i].get_id_num())
			{
				counts[0]++;
				counts[counts[0]]=i;
			}
		}
		if(counts[0]>0)
		{
		    cout<<"������"<<counts[0]<<"��ѧ��:"<<endl;
            put_one();
            for(int j=1;j<=counts[0];j++)//�������ƥ���ѧ����Ϣ
            {
                put_two(p+counts[j]);
            }
            return counts;
		}
        cout<<"    δ�ҷ���������ѧ������Ϣ!"<<endl;
		do{
			cout<<"�Ƿ���������֤��������ѧ����Ϣ��(y/n)";
			scanf_s("%c",&Right);
			while(getchar()!='\n');
			if(Right!='y'&&Right!='n')
				cout<<"    �������"<<endl;
		}while(Right!='y'&&Right!='n');
	}while(Right=='y');
	goto search0;


}

//ɾ��ѧ����¼
//���ܣ����ղ�ͬ�������������Ӧѧ����Ϣ
//      ��ѡ��ɾ��
void Delete(student *p,int *get_num)
{
	int i;
	char Right,exam_num[13];
Delete0:
	if(*get_num==0)
    {
		cout<<"    ��ǰϵͳ��û��ѧ�����ݣ�����¼�����ݣ�\n"<<endl;
		return;
    }
    int counts[101],*q=counts;//���ڲ�ѯѧ����counts[0]������������������������ҵ������
    int choose;
    cout<<"    ����Ҫɾ������ѧ������Ϣ?"<<endl;
    q=Search(p,*get_num,counts);
    if(q[0]==0)  goto Delete2;
    if(q[0]==1)
    {
        choose=q[1];
        goto Delete1_1;
    }
    do
    {
        choose=0;
        cout<<"��Ҫɾ����������������¼��(������������<";
        for(int i=1;i<q[0];i++)
            cout<<q[i]+1<<"��";
        cout<<q[q[0]]+1<<">)";
        char str[4];
        gets_s(str);
        for(int i=0;str[i]!='\0';i++)
            choose=choose*10+str[i]-48;
        choose--;//�����������1��ɶ�Ӧ�������ڵ��±�
        for(int i=1;i<-q[0];i++)
        {
            if(choose==q[i])
            {
                cout<<"��ѡ����ǣ�"<<endl;
                goto Delete1;
            }
        }
        cout<<"    ������󣡣�����������"<<endl;
    }while(1);
Delete1:
    put_one();
    put_two(p+choose);
Delete1_1:
        do{
        cout<<"��Ҫɾ����ѧ������Ϣ��(y/n)";
        scanf_s("%c",&Right);
        if(Right=='\n')
            goto Delete1_1;
        else
            while(getchar()!='\n');
        if(Right!='y'&&Right!='n')
            cout<<"    �������"<<endl;
    }while(Right!='y'&&Right!='n');
    if(Right=='y')
    {
        for(;choose<*get_num-1;choose++)////ɾ�������
        {
            *(p+choose)=*(p+choose+1);
            (p+choose)->ranking--;
        }
        *get_num=*get_num-1;
        cout<<"ɾ���ɹ���"<<endl;
    }
Delete2:
    do{
        cout<<"�Ƿ�Ҫɾ������ѧ����Ϣ��(y/n)";
        scanf_s("%c",&Right);
        if(Right=='\n')
            Right=0;
        else
            while(getchar()!='\n');
        if(Right!='y'&&Right!='n'&&Right!='\n')
            cout<<"    �������"<<endl;
    }while(Right!='y'&&Right!='n');
    if(Right=='y')
        goto Delete0;
	cout<<"���س�������...";
	getchar();
}

//����Ƽ��ܷ�ƽ���ֲ����ش���ƽ���ֵ�ָ��
double *Average_score(student *p,int get_num)
{
    int sum[5]={0};
    static double aver[5];
    for(int i=0;i<get_num;i++)
    {
        sum[0]+=p[i].scores[0];
        sum[1]+=p[i].scores[1];
        sum[2]+=p[i].scores[2];
        sum[3]+=p[i].scores[3];
        sum[4]+=p[i].sum_score;
    }
    aver[0]=(double)sum[0]/get_num;
    aver[1]=(double)sum[1]/get_num;
    aver[2]=(double)sum[2]/get_num;
    aver[3]=(double)sum[3]/get_num;
    aver[4]=(double)sum[4]/get_num;
    return aver;
}

//���ܣ�����������ε���������߷֣���ͷ�
//      ��ӡ�����ε���������߷֣���ͷֺ�ƽ����
void Analyse(student *p,int get_num)
{
	if(get_num==0) {
		cout<<"    ��ǰϵͳ��û����ѡ���ѧ�����ݣ�����¼�����ݣ�\n"<<endl;
		return ;}
    double max_score[5]={0.0},min_score[5]={150.0,150.0,150.0,300.0,750.0};
    int stage_num[5][4]={0};
    for(int i=0;i<get_num;i++)
    {
        //������Ӣ��
        for(int j=0;j<3;j++)
        {
            if(p[i].scores[j]>127)  stage_num[j][0]++;
            else if(p[i].scores[j]>=105)  stage_num[j][1]++;
            else if(p[i].scores[j]>=90)  stage_num[j][2]++;
            else  stage_num[j][3]++;
            max_score[j]=(max_score[j]>p[i].scores[j]) ? max_score[j]:p[i].scores[j];
            min_score[j]=(min_score[j]<p[i].scores[j]) ? min_score[j]:p[i].scores[j];
        }
        //������ۺϣ�
        if(p[i].scores[3]>=255)  stage_num[3][0]++;
        else if(p[i].scores[3]>=210)  stage_num[3][1]++;
        else if(p[i].scores[3]>=180)  stage_num[3][2]++;
        else  stage_num[3][3]++;
        max_score[3]=(max_score[3]>p[i].scores[3]) ? max_score[3]:p[i].scores[3];
        min_score[3]=(min_score[3]<p[i].scores[3]) ? min_score[3]:p[i].scores[3];
        //������ܷ֣�
        if(p[i].sum_score>637)  stage_num[4][0]++;
        else if(p[i].sum_score>=525)  stage_num[4][1]++;
        else if(p[i].sum_score>=450)  stage_num[4][2]++;
        else  stage_num[4][3]++;
        max_score[4]=(max_score[4]>p[i].sum_score) ? max_score[4]:p[i].sum_score;
        min_score[4]=(min_score[4]<p[i].sum_score) ? min_score[4]:p[i].sum_score;
    }
    double aver[5],*q=aver;
    q=Average_score(p,get_num);
    cout<<"  ����Ӣ��  �ţ�>127������>=105������>=90��������<90"<<endl;
    cout<<"    �ۺϣ�  �ţ�>=255������>=210������>=180��������<180"<<endl;
    cout<<"    �ܷ֣�  �ţ�>637������>=525������>=450��������<450"<<endl<<endl;
	cout<<"|  ��Ŀ  |   ��   |   ��   |  ����  | ������ |��߷�|��ͷ�|ƽ����|"<<endl;
	cout<<"|--------|--------|--------|--------|--------|------|------|------|"<<endl;
    printf("|  ����  |%4d��  |%4d��  |%4d��  |%4d��  | %5.1lf| %5.1lf| %5.1lf|\n",stage_num[0][0],stage_num[0][1],stage_num[0][2],stage_num[0][3],max_score[0],min_score[0],q[0]);
    printf("|  ��ѧ  |%4d��  |%4d��  |%4d��  |%4d��  | %5.1lf| %5.1lf| %5.1lf|\n",stage_num[1][0],stage_num[1][1],stage_num[1][2],stage_num[1][3],max_score[1],min_score[1],q[1]);
    printf("|  Ӣ��  |%4d��  |%4d��  |%4d��  |%4d��  | %5.1lf| %5.1lf| %5.1lf|\n",stage_num[2][0],stage_num[2][1],stage_num[2][2],stage_num[2][3],max_score[2],min_score[2],q[2]);
    printf("|  �ۺ�  |%4d��  |%4d��  |%4d��  |%4d��  | %5.1lf| %5.1lf| %5.1lf|\n",stage_num[3][0],stage_num[3][1],stage_num[3][2],stage_num[3][3],max_score[3],min_score[3],q[3]);
    printf("|  �ܷ�  |%4d��  |%4d��  |%4d��  |%4d��  | %5.1lf| %5.1lf| %5.1lf|\n",stage_num[4][0],stage_num[4][1],stage_num[4][2],stage_num[4][3],max_score[4],min_score[4],q[4]);
	cout<<"-----------------------------------------------------------------"<<endl;
	cout<<"���س�������...";
	getchar();

}


//ͳ�������
//���ܣ�������ơ��Ա����
//      �õ�Analyse
void Analysis(student *p,int get_num)
{
	int num;//�����ѡ��
	if(get_num==0) {
		cout<<"    ��ǰϵͳ��û��ѧ�����ݣ�����¼�����ݣ�\n"<<endl;
		return ;}
    student* Science = new student[get_num];
    student* Art = new student[get_num];
    student* Men = new student[get_num];
    student* Women = new student[get_num];
    int s,a,m,w;
    s=a=m=w=0;
    for(int i=0;i<get_num;i++)
    {
        if(p[i].get_is_science())
            Science[s++]=p[i];
        else
            Art[a++]=p[i];
        if(p[i].get_sex())
            Men[m++]=p[i];
        else
            Women[w++]=p[i];
    }
    print_analysis_options();
    cout<<"                         ������ѡ��(0-5):";
    scanf_s("%d",&num);
    while(getchar()!='\n');
    switch(num)
    {
		case 1 : Analyse(p,get_num);break;
		case 2 : Analyse(Science,s);break;
		case 3 : Analyse(Art,a);break;
		case 4 : Analyse(Men,m);break;
		case 5 : Analyse(Women,w);break;
		case 0 : return ;
		default : cout<<"�����������������...\n"<<endl;
	}
}


