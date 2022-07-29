#include "高考成绩管理系统_head.h"
#include "OrderList_head.h"
#include <string.h>
#include <stdlib.h>

using namespace std;

//打印主菜单选项
void print_options()
{
	cout<<"    ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
	cout<<"    +                                                          +"<<endl;
	cout<<"    +                     高考成绩管理系统                     +"<<endl;
	cout<<"    +                                                          +"<<endl;
	cout<<"    +                    1 --- 录入学生信息                    +"<<endl;
	cout<<"    +                    2 --- 修改学生信息                    +"<<endl;
	cout<<"    +                    3 --- 查询学生成绩                    +"<<endl;
	cout<<"    +                    4 --- 删除学生信息                    +"<<endl;
	cout<<"    +                    5 --- 浏览学生成绩                    +"<<endl;
	cout<<"    +                    6 --- 统计与分析                      +"<<endl;
	cout<<"    +                    0 --- 退出系统                        +"<<endl;
	cout<<"    +                                                          +"<<endl;
	cout<<"    ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n"<<endl;
}

//打印搜索菜单选项
void print_search_options()
{
	cout<<"    ++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
	cout<<"    +                                                      +"<<endl;
	cout<<"    +                     查询学生信息                     +"<<endl;
	cout<<"    +                                                      +"<<endl;
	cout<<"    +                  1 --- 按照准考证号查询              +"<<endl;
	cout<<"    +                  2 --- 按照姓名查询                  +"<<endl;
	cout<<"    +                  3 --- 按照身份证号查询              +"<<endl;
	cout<<"    +                  0 --- 退出查询                      +"<<endl;
	cout<<"    +                                                      +"<<endl;
	cout<<"    ++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n"<<endl;
}

//打印统计与分析菜单选项
void print_analysis_options()
{
	cout<<"    +++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
	cout<<"    +                                                     +"<<endl;
	cout<<"    +                     统计与分析                      +"<<endl;
	cout<<"    +                                                     +"<<endl;
	cout<<"    +                  1 --- 所有学生                     +"<<endl;
	cout<<"    +                  2 --- 理科                         +"<<endl;
	cout<<"    +                  3 --- 文科                         +"<<endl;
	cout<<"    +                  4 --- 男生                         +"<<endl;
	cout<<"    +                  5 --- 女生                         +"<<endl;
	cout<<"    +                  0 --- 退出                         +"<<endl;
	cout<<"    +                                                     +"<<endl;
	cout<<"    +++++++++++++++++++++++++++++++++++++++++++++++++++++++\n"<<endl;
}

//打印成绩界面（下面2个函数）
void put_one()
{
	cout<<"|   准考证号   |   姓名   | 语文 | 数学 | 英语 | 理综/文综 | 总成绩 | 排名 |"<<endl;
	cout<<"|--------------|----------|------|------|------|-----------|--------|------|"<<endl;
}
void put_two(student *p)
{
	printf("|%5s|%6s(%s)|%5.1lf |%5.1lf |",p->get_exam_num(),p->get_name(),p->Sex,p->get_Chinese_score(),p->get_Math_score());
	printf("%5.1lf |%5.1lf(%s)|%6.1lf  |  %-4d|\n",p->get_Engliish_score(),p->get_Other_score(),p->subject,p->sum_score,p->ranking);
}

//浏览全部学生成绩（排好序的）
void Look(student *p,int get_num)
{
	int i;
	if(get_num==0) {
		cout<<"    当前系统还没有学生数据！请先录入数据：\n"<<endl;
		return;}
	put_one();
	for(i=0;i<get_num;i++)
	{
		put_two(p);
		p++;
	}
	cout<<"按回车键继续...";
	getchar();
}

//按总成绩排序
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

//连续录入学生信息
//返回：学生个数
int set_information(student *p,int get_num)
{
	int i;
	char str[16];
	for(i=get_num;;i++)
	{
		cout<<"请输入学生的14位准考证号（以准考证号为0结束录入）：";
loop0:
        gets_s(str);
		if(strcmp(str,"0")==0)       return i;
        if(str[0]=='\0')
        {
            cout<<"(提示：此项为必填项！！)\n请输入准考证号：";
            goto loop0;
        }
        if(check_exam_num(str))
        {
            p[i].set_exam_num(str);
        }
        else
        {
            cout<<"输入准考证号不合法！请重新输入：";
            goto loop0;
        }
		p[i].set_all(str);
	}
}

//修改学生信息
//功能：按照不同搜索项搜索相对应学生信息
//      并选择修改
void Update(student *p,const int get_num)
{
	if(get_num==0)
    {
		cout<<"    当前系统还没有学生数据！请先录入数据：\n"<<endl;
		return;
    }
    char Right;

Update0:
    do
    {
        int counts[101],*q=counts;//用于查询学生，counts[0]用来计数，其它用来储存查找到的序号
        int choose;
        cout<<"    你想要修改哪名学生的信息?"<<endl;
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
			cout<<"您要修改的是以上哪条记录？（请输入其排名<";
			for(int i=1;i<q[0];i++)
                cout<<q[i]+1<<"，";//输出的排名比下标多一
            cout<<q[q[0]]+1<<">）：";
            char str[4];
            gets_s(str);
            for(int i=0;str[i]!='\0';i++)
                choose=choose*10+str[i]-48;
            choose--;//输入的排名减1变成对应在数组内的下标
            for(int i=0;i<=q[0];i++)
            {
                if( (choose)==q[i])
                    goto Update1;
            }
            cout<<"    输入错误！！请重新输入"<<endl;
        }while(1);
Update1:
        put_one();
        put_two(p+choose);
Update1_1:
        do{
			cout<<"您要修改该学生的信息吗？(y/n)";
			scanf_s("%c",&Right);
			if(Right=='\n')
                goto Update1_1;
            else
                while(getchar()!='\n');
			if(Right!='y'&&Right!='n')
				cout<<"    输入错误！"<<endl;
		}while(Right!='y'&&Right!='n');
		if(Right=='y')
		{
		    char str[16];
		    cout<<"请输入学生的14位准考证号：";
Update2:
		    gets_s(str);
		    if(strcmp(str,"0")==0)       return;
		    if(str[0]=='\0')
            {
                cout<<"(提示：此项为必填项！！)\n请输入准考证号：";
        	    goto Update2;
            }
        	if(check_exam_num(str))
        	{
                p[choose].set_exam_num(str);
            }
            else
            {
                cout<<"输入准考证号不合法！请重新输入：";
                goto Update2;
            }
                p[choose].set_all(str);
        }
Update3:
        do
        {
            cout<<"是否继续修改其他学生信息？(y/n)";
            scanf_s("%c",&Right);
            if(Right=='\n')
                Right=0;
            else
                while(getchar()!='\n');
            if(Right!='y'&&Right!='n'&&Right!='\n')
                cout<<"    输入错误！"<<endl;
        }while(Right!='y'&&Right!='n');
	}while(	Right=='y');
	cout<<"按回车键继续...";
	getchar();
}

//查询学生信息
//功能：按照不同搜索项搜索相对应学生信息并打印出来
//返回：携带查询到的学生对应下标的指针
int *Search(student *p,int get_num,int counts[])
{
    counts[0]=0;//counts[0]用来计数，其它用来储存查找到的序号
	int i,n;
	char Right,str[17];
	if(get_num==0) {
		cout<<"    当前系统还没有学生数据！请先录入数据：\n"<<endl;
		return counts;}
search0:
	while(1)
    {
		print_search_options();
		cout<<"                         请输入选项(0-3):";
		scanf_s("%d",&n);
		while(getchar()!='\n');
        switch(n)
		{
		case 1 : goto search1;break;
		case 2 : goto search2;break;
		case 3 : goto search3;break;
		case 0 : return counts;
		default : cout<<"输入错误！请重新输入...\n"<<endl;
		}
	}
search1:
    do
    {
        counts[0]=0;//counts[0]用来计数，其它用来储存查找到的序号
		int find=0;
        cout<<"请输入要搜索的学生的准考证号（输入0返回）：";
        gets_s(str);
		if(strcmp(str,"0")==0)       goto search0;
        if(str[0]=='\0')
        {
            goto search1;
        }
        if(check_exam_num(str)==false)
        {
            cout<<"输入准考证号不合法！请重新输入："<<endl;
            goto search1;
        }
		for(i=0;i<get_num;i++)//匹配查询
		{
			if(strcmp(p[i].get_exam_num(),str)==0)
			{
				counts[0]++;
				counts[counts[0]]=i;
			}
		}
		if(counts[0]>0)
		{
		    cout<<"搜索到"<<counts[0]<<"个学生:"<<endl;
            put_one();
            for(int j=1;j<=counts[0];j++)//输出所有匹配的学生信息
            {
                put_two(p+counts[j]);
            }
            return counts;
		}

        cout<<"    未找符合搜索项学生的信息!"<<endl;
		do{
			cout<<"是否继续按准考证号搜索学生信息？(y/n)";
			scanf_s("%c",&Right);
			while(getchar()!='\n');
			if(Right!='y'&&Right!='n')
				cout<<"    输入错误！"<<endl;
		}while(Right!='y'&&Right!='n');
	}while(Right=='y');
	goto search0;
search2:
    do
    {
        counts[0]=0;//counts[0]用来计数，其它用来储存查找到的序号
		int find=0;
        cout<<"请输入要搜索的学生的姓名（输入0返回）：";
        gets_s(str);
		if(strcmp(str,"0")==0)       goto search0;
        if(str[0]=='\0')
        {
            goto search2;
        }
        if(check_name(str)==false)
        {
            cout<<"输入的姓名不合法！请重新输入：";
            goto search2;
        }
		for(i=0;i<get_num;i++)//匹配查询
		{
			if(strcmp((p+i)->get_name(),str)==0)
			{
				counts[0]++;
				counts[counts[0]]=i;
			}
		}
		if(counts[0]>0)
		{
		    cout<<"搜索到"<<counts[0]<<"个学生:"<<endl;
            put_one();
            for(int j=1;j<=counts[0];j++)//输出所有匹配的学生信息
            {
                put_two(p+counts[j]);
            }
            return counts;
		}
        cout<<"    未找符合搜索项学生的信息!"<<endl;
		do{
			cout<<"是否继续按姓名搜索学生信息？(y/n)";
			scanf_s("%c",&Right);
			while(getchar()!='\n');
			if(Right!='y'&&Right!='n')
				cout<<"    输入错误！"<<endl;
		}while(Right!='y'&&Right!='n');
	}while(Right=='y');
	goto search0;
search3:
    do
    {
        counts[0]=0;//counts[0]用来计数，其它用来储存查找到的序号
		int find=0;
        cout<<"请输入要搜索的学生的身份证号码（输入0返回）：";
        ID student_id;
        cin>>student_id;
        if(student_id.year==-1)     goto search3;
		if(student_id.year==0)       goto search0;
		for(i=0;i<get_num;i++)//匹配查询
		{
			if(student_id==p[i].get_id_num())
			{
				counts[0]++;
				counts[counts[0]]=i;
			}
		}
		if(counts[0]>0)
		{
		    cout<<"搜索到"<<counts[0]<<"个学生:"<<endl;
            put_one();
            for(int j=1;j<=counts[0];j++)//输出所有匹配的学生信息
            {
                put_two(p+counts[j]);
            }
            return counts;
		}
        cout<<"    未找符合搜索项学生的信息!"<<endl;
		do{
			cout<<"是否继续按身份证号码搜索学生信息？(y/n)";
			scanf_s("%c",&Right);
			while(getchar()!='\n');
			if(Right!='y'&&Right!='n')
				cout<<"    输入错误！"<<endl;
		}while(Right!='y'&&Right!='n');
	}while(Right=='y');
	goto search0;


}

//删除学生记录
//功能：按照不同搜索项搜索相对应学生信息
//      并选择删除
void Delete(student *p,int *get_num)
{
	int i;
	char Right,exam_num[13];
Delete0:
	if(*get_num==0)
    {
		cout<<"    当前系统还没有学生数据！请先录入数据：\n"<<endl;
		return;
    }
    int counts[101],*q=counts;//用于查询学生，counts[0]用来计数，其它用来储存查找到的序号
    int choose;
    cout<<"    你想要删除哪名学生的信息?"<<endl;
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
        cout<<"您要删除的是以上哪条记录？(请输入其排名<";
        for(int i=1;i<q[0];i++)
            cout<<q[i]+1<<"，";
        cout<<q[q[0]]+1<<">)";
        char str[4];
        gets_s(str);
        for(int i=0;str[i]!='\0';i++)
            choose=choose*10+str[i]-48;
        choose--;//输入的排名减1变成对应在数组内的下标
        for(int i=1;i<-q[0];i++)
        {
            if(choose==q[i])
            {
                cout<<"你选择的是："<<endl;
                goto Delete1;
            }
        }
        cout<<"    输入错误！！请重新输入"<<endl;
    }while(1);
Delete1:
    put_one();
    put_two(p+choose);
Delete1_1:
        do{
        cout<<"您要删除该学生的信息吗？(y/n)";
        scanf_s("%c",&Right);
        if(Right=='\n')
            goto Delete1_1;
        else
            while(getchar()!='\n');
        if(Right!='y'&&Right!='n')
            cout<<"    输入错误！"<<endl;
    }while(Right!='y'&&Right!='n');
    if(Right=='y')
    {
        for(;choose<*get_num-1;choose++)////删除代码块
        {
            *(p+choose)=*(p+choose+1);
            (p+choose)->ranking--;
        }
        *get_num=*get_num-1;
        cout<<"删除成功！"<<endl;
    }
Delete2:
    do{
        cout<<"是否还要删除其他学生信息？(y/n)";
        scanf_s("%c",&Right);
        if(Right=='\n')
            Right=0;
        else
            while(getchar()!='\n');
        if(Right!='y'&&Right!='n'&&Right!='\n')
            cout<<"    输入错误！"<<endl;
    }while(Right!='y'&&Right!='n');
    if(Right=='y')
        goto Delete0;
	cout<<"按回车键继续...";
	getchar();
}

//求各科及总分平均分并返回存有平均分的指针
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

//功能：计算各分数段的人数，最高分，最低分
//      打印分数段的人数，最高分，最低分和平均分
void Analyse(student *p,int get_num)
{
	if(get_num==0) {
		cout<<"    当前系统还没有所选项的学生数据！请先录入数据：\n"<<endl;
		return ;}
    double max_score[5]={0.0},min_score[5]={150.0,150.0,150.0,300.0,750.0};
    int stage_num[5][4]={0};
    for(int i=0;i<get_num;i++)
    {
        //对语数英：
        for(int j=0;j<3;j++)
        {
            if(p[i].scores[j]>127)  stage_num[j][0]++;
            else if(p[i].scores[j]>=105)  stage_num[j][1]++;
            else if(p[i].scores[j]>=90)  stage_num[j][2]++;
            else  stage_num[j][3]++;
            max_score[j]=(max_score[j]>p[i].scores[j]) ? max_score[j]:p[i].scores[j];
            min_score[j]=(min_score[j]<p[i].scores[j]) ? min_score[j]:p[i].scores[j];
        }
        //下面对综合：
        if(p[i].scores[3]>=255)  stage_num[3][0]++;
        else if(p[i].scores[3]>=210)  stage_num[3][1]++;
        else if(p[i].scores[3]>=180)  stage_num[3][2]++;
        else  stage_num[3][3]++;
        max_score[3]=(max_score[3]>p[i].scores[3]) ? max_score[3]:p[i].scores[3];
        min_score[3]=(min_score[3]<p[i].scores[3]) ? min_score[3]:p[i].scores[3];
        //下面对总分：
        if(p[i].sum_score>637)  stage_num[4][0]++;
        else if(p[i].sum_score>=525)  stage_num[4][1]++;
        else if(p[i].sum_score>=450)  stage_num[4][2]++;
        else  stage_num[4][3]++;
        max_score[4]=(max_score[4]>p[i].sum_score) ? max_score[4]:p[i].sum_score;
        min_score[4]=(min_score[4]<p[i].sum_score) ? min_score[4]:p[i].sum_score;
    }
    double aver[5],*q=aver;
    q=Average_score(p,get_num);
    cout<<"  语数英：  优：>127，良：>=105，及格：>=90，不及格：<90"<<endl;
    cout<<"    综合：  优：>=255，良：>=210，及格：>=180，不及格：<180"<<endl;
    cout<<"    总分：  优：>637，良：>=525，及格：>=450，不及格：<450"<<endl<<endl;
	cout<<"|  科目  |   优   |   良   |  及格  | 不及格 |最高分|最低分|平均分|"<<endl;
	cout<<"|--------|--------|--------|--------|--------|------|------|------|"<<endl;
    printf("|  语文  |%4d人  |%4d人  |%4d人  |%4d人  | %5.1lf| %5.1lf| %5.1lf|\n",stage_num[0][0],stage_num[0][1],stage_num[0][2],stage_num[0][3],max_score[0],min_score[0],q[0]);
    printf("|  数学  |%4d人  |%4d人  |%4d人  |%4d人  | %5.1lf| %5.1lf| %5.1lf|\n",stage_num[1][0],stage_num[1][1],stage_num[1][2],stage_num[1][3],max_score[1],min_score[1],q[1]);
    printf("|  英语  |%4d人  |%4d人  |%4d人  |%4d人  | %5.1lf| %5.1lf| %5.1lf|\n",stage_num[2][0],stage_num[2][1],stage_num[2][2],stage_num[2][3],max_score[2],min_score[2],q[2]);
    printf("|  综合  |%4d人  |%4d人  |%4d人  |%4d人  | %5.1lf| %5.1lf| %5.1lf|\n",stage_num[3][0],stage_num[3][1],stage_num[3][2],stage_num[3][3],max_score[3],min_score[3],q[3]);
    printf("|  总分  |%4d人  |%4d人  |%4d人  |%4d人  | %5.1lf| %5.1lf| %5.1lf|\n",stage_num[4][0],stage_num[4][1],stage_num[4][2],stage_num[4][3],max_score[4],min_score[4],q[4]);
	cout<<"-----------------------------------------------------------------"<<endl;
	cout<<"按回车键继续...";
	getchar();

}


//统计与分析
//功能：按文理科、性别分类
//      用到Analyse
void Analysis(student *p,int get_num)
{
	int num;//输入的选项
	if(get_num==0) {
		cout<<"    当前系统还没有学生数据！请先录入数据：\n"<<endl;
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
    cout<<"                         请输入选项(0-5):";
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
		default : cout<<"输入错误！请重新输入...\n"<<endl;
	}
}


