#include "�߿��ɼ�����ϵͳ_head.h"
#include "OrderList_head.h"

using namespace std;
int main(void)
{
    cout<<"    ���ԣ���ϵͳ�Ը�������Ҳ����������Ӧ��飨���鷳��~��"<<endl<<endl<<endl;
    int counts[101];//���ڲ�ѯѧ����counts[0]������������������������ҵ����������
	student Students[100];
	int n,get_num=0;//get_numΪĿǰϵͳ�ڵ�ѧ������
	while(1){
		print_options();
		cout<<"                         ������ѡ��(0-6):";
		scanf_s("%d",&n);
		while(getchar()!='\n');
        switch(n)
		{
		case 1 : get_num=set_information(Students,get_num);Order(Students,get_num);break;
		case 2 : Update(Students,get_num);Order(Students,get_num);break;
		case 3 :
		    Search(Students,get_num,counts);
            printf("���س�������...");
            getchar();break;
		case 4 : Delete(Students,&get_num);Order(Students,get_num);break;
		case 5 : Look(Students,get_num);break;
		case 6 : Analysis(Students,get_num);break;
		case 0 : cout<<"\n                      ��лʹ�ñ�ϵͳ���ټ�~  ^o^"<<endl;return 0;
		default : cout<<"�����������������...\n"<<endl;
		}
	}
}
