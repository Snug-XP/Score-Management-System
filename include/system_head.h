#include <iostream>
#include "Date_head.h"
#include "ID_head.h"

bool check_name(char *str);//检查输入的名字是否合法，返回true为合法
bool check_exam_num(char *str);//检查输入的准考证号是否合法，返回true为合法
class student
{
    char exam_num[16];
    char name [41];
    bool sex;/////ture为男，false为女
    Date birthday;
    ID id_num;
    bool is_science;//ture为理科，false为文科
    bool has_exam_num,has_name,has_sex,has_birthday,has_id_num,has_is_science,has_scores;
public:
    double scores[4];
    char subject[5];
    char Sex[3];
    double sum_score;
    int ranking;
    student( );//构造函数
    void set_exam_num(char str[]);//输入准考证号
    void set_name( );//输入姓名
    void set_sex( );//选择性别
    void set_birthday( );//输入出生日
    void set_id_num( );//输入身份证号码
    void set_is_science( );//选择文理科
    void set_scores( );//输入考试成绩
    void set_all( char str[]);//输入所有信息(str为准考证号，由于需判断结束录入，因此在all外面判断录入的准考证号）
    char *get_exam_num()  {return exam_num;}
    char *get_name()  {return name;}
    ID get_id_num()  {return id_num;}
    bool get_is_science()  {return is_science;}
    bool get_sex() {return sex;}
    double get_Chinese_score()  {return scores[0];}
    double get_Math_score()  {return scores[1];}
    double get_Engliish_score()  {return scores[2];}
    double get_Other_score()  {return scores[3];}
};


