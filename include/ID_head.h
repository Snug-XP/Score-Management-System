#include <stdio.h>
#include <iostream>
// # author������
char get_right_lastnum(char const *a);//�������֤ǰ17λ����������һλУ����
bool check_exist(int a[],int code,int n);//��������������code�Ƿ�������������a������

class ID
{
    char id_num[19];
public:
    int year,month,day;
    char lastnum;
    char right_lastnum;
    bool sex;//tureΪ�У�falseΪŮ
    ID()  {year=-1;}
    void set_id(char *str);
    char *get_id(){return id_num;}
    bool check_id(char const *str);
    ID &operator=( ID &id);//���ظ�ֵ�����
    bool operator==(const ID &id);//����==�����
    friend std::istream &operator>>(std::istream &in,ID &id);
    friend std::ostream &operator<<(std::ostream &out,ID &id);
};
