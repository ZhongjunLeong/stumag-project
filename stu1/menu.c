#include <stdio.h>
#include "menu.h"
//extern enum function choose;
void menu()
{
        printf("---------------------------------------\n");
        printf("enter you choose\n");
        printf("1 :store student info 2：find student score 3：quit\n");
        printf("---------------------------------------\n");
 }
struct score *stu_create(struct score *stu)
{
  printf("input student id:\n");
  scanf("%d",stu->id);
  printf("input student name:\n");
  scanf("%s",stu->name);
  printf("input student math score:\n");
  scanf("%d",stu->math);
  printf("input student chinese score:\n");
  scanf("%d",stu->chinese);
  return stu;
}

void stu_info(struct score*ptr)
{
  FILE *fp;
  struct score *st;
  size_t size,fw;
  size = sizeof(struct score);
  fp = fopen(FNAME,r+);
  if(fp == NULL)
  {
    perror("open()");
    exit(1);
  }
 
  st = stu_create(ptr);
  fw = fwrite(st,size,1,fp);
  if(fw == 1)
  {
    fputc('\n',fp);
    printf("sucess line wrap and write\n");
  }
  if(fw < 1)
  {
    perror("fwrite()");
    exit(1);
  }
  close(fp);
}

//  printf("stu_info\n");



void stu_find(int stu_id)
{
 
  printf("stu_find\n");


//  return 0;
}
