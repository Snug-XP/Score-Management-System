#include <iostream>
#include "Date_head.h"
#include "ID_head.h"

bool check_name(char *str);//�������������Ƿ�Ϸ�������trueΪ�Ϸ�
bool check_exam_num(char *str);//��������׼��֤���Ƿ�Ϸ�������trueΪ�Ϸ�
class student
{
    char exam_num[16];
    char name [41];
    bool sex;/////tureΪ�У�falseΪŮ
    Date birthday;
    ID id_num;
    bool is_science;//tureΪ��ƣ�falseΪ�Ŀ�
    bool has_exam_num,has_name,has_sex,has_birthday,has_id_num,has_is_science,has_scores;
public:
    double scores[4];
    char subject[5];
    char Sex[3];
    double sum_score;
    int ranking;
    student( );//���캯��
    void set_exam_num(char str[]);//����׼��֤��
    void set_name( );//��������
    void set_sex( );//ѡ���Ա�
    void set_birthday( );//���������
    void set_id_num( );//�������֤����
    void set_is_science( );//ѡ�������
    void set_scores( );//���뿼�Գɼ�
    void set_all( char str[]);//����������Ϣ(strΪ׼��֤�ţ��������жϽ���¼�룬�����all�����ж�¼���׼��֤�ţ�
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


