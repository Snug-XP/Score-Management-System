
void print_options();//打印主菜单选项
void print_search_options();//打印搜索菜单选项
void Look(student *p,int get_num);//浏览学生成绩
void Order(student *p,int get_num);//按总成绩排序
int set_information(student *p,int get_num);//录入学生信息
void Update(student *p,const int get_num);//修改学生信息
int *Search(student *p,int get_num,int counts[]);//查询学生信息
void Delete(student *p,int *get_num);//删除学生信息
void Analysis(student *p,int get_num);//统计与分析(主目录)
double *Average_score(student *p,int get_num);//求各科及总分平均分并返回存有平均分的指针
void Analyse(student *p,int get_num);//打印各分数段的人数，最高分，最低分和平均分

