#ifndef _MENU_H
#define _MENU_H
#define NAMESIZE 32
#define FNAME "./test"
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
  char name[NAMESIZE];
  int math;
  int chinese;
};
void menu();
void stu_info(struct score *);
void stu_find(int);

#endif
