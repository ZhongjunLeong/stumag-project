#ifndef _MENU_H
#define _MENU_H
#define NAMESIZE 32
enum funtion
{
    student_info = 1,
    student_find,
    quit
};
enum funtion choose;
struct score
{
  int id;
  int name[NAMESIZE];
  int math;
  int chinese;
};
void menu();
void *stu_info(struct score *);
void stu_find(int);

#endif
