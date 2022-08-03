#include "system_head.h"
#include "OrderList_head.h"
# author：向鹏

using namespace std;
int main(void)
{
    cout<<"    序言：本系统对各种输入也都有做出相应检查（最麻烦的~）"<<endl<<endl<<endl;
    int counts[101];//用于查询学生，counts[0]用来计数，其它用来储存查找到的排名序号
	student Students[100];
	int n,get_num=0;//get_num为目前系统内的学生数量
	while(1){
		print_options();
		cout<<"                         请输入选项(0-6):";
		scanf("%d",&n);
		while(getchar()!='\n');
        switch(n)
		{
		case 1 : get_num=set_information(Students,get_num);Order(Students,get_num);break;
		case 2 : Update(Students,get_num);Order(Students,get_num);break;
		case 3 :
		    Search(Students,get_num,counts);
            printf("按回车键继续...");
            getchar();break;
		case 4 : Delete(Students,&get_num);Order(Students,get_num);break;
		case 5 : Look(Students,get_num);break;
		case 6 : Analysis(Students,get_num);break;
		case 0 : cout<<"\n                      感谢使用本系统，再见~  ^o^"<<endl;return 0;
		default : cout<<"输入错误！请重新输入...\n"<<endl;
		}
	}
}
