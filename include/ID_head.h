#include <stdio.h>
#include <iostream>
// # author：向鹏
char get_right_lastnum(char const *a);//根据身份证前17位数字求出最后一位校验码
bool check_exist(int a[],int code,int n);//检查你输入的区划code是否在所有区划的a数组中

class ID
{
    char id_num[19];
public:
    int year,month,day;
    char lastnum;
    char right_lastnum;
    bool sex;//ture为男，false为女
    ID()  {year=-1;}
    void set_id(char *str);
    char *get_id(){return id_num;}
    bool check_id(char const *str);
    ID &operator=( ID &id);//重载赋值运算符
    bool operator==(const ID &id);//重载==运算符
    friend std::istream &operator>>(std::istream &in,ID &id);
    friend std::ostream &operator<<(std::ostream &out,ID &id);
};
