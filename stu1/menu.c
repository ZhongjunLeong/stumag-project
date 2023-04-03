#include <stdio.h>
#include <stdlib.h>
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
  struct score *stu_st = stu;
  stu_st = malloc(sizeof(struct score));
  printf("input student id:\n");
  scanf("%d",&stu_st->id);
  printf("input student name:\n");
  scanf("%s",stu_st->name);
  printf("input student math score:\n");
  scanf("%d",&stu_st->math);
  printf("input student chinese score:\n");
  scanf("%d",&stu_st->chinese);
  return stu_st;
}

void stu_info(struct score*ptr)
{
  FILE *fp;
  struct score *st,*st_r;
  size_t size,fw,fr;
  char ch;
  size = sizeof(struct score);

  fp = fopen(FNAME,"r+");
  if(fp == NULL)
  {
    perror("open()");
    exit(1);
  }
 
//  printf("all ready open and store1");
  st = stu_create(ptr);

//  printf("id:%d,name:%s,math:%d,chinses:%d\n",st->id,st->name,st->math,st->chinese);
 // printf("all ready open and store2");
  fseek(fp,0,SEEK_SET);

 // printf("all ready open and store3");
 //   printf("read&write\n");
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
  fseek(fp,0,SEEK_SET);
  fread(st_r,size,1,fp);
  printf("id:%d,name:%s,math:%d,chinses:%d\n",st_r->id,st_r->name,st_r->math,st_r->chinese);
 // free(stu_st);
  close(fp);
}

//  printf("stu_info\n");



void stu_find(int stu_id)
{
  size_t size = 0;
  ssize_t gl;
  FILE *fd;
  char *cur = NULL;
  cur = malloc(size * sizeof(char));
  if(cur == NULL)
  {
    perror("unable to allocate cur");
    exit(1);
  }
  fd = fopen(FNAME,"r");
  if(fd == NULL)
  {
    perror("open()");
    exit(1);
  }
 while(1)
 {
  gl = getline(&cur,&size,fd);
  if(*cur->id == stu_id)
  {
    printf("FIND:id:%d,name:%s,math:%d,chinses:%d\n",*cur->id,cur->name,cur->math,cur->chinese);
  }
  if(gl < 0)
  {
    printf("fail getline");
    break;
  }
  printf("getline return num:%d\n",gl);
 }
  free(cur);
//  return 0;
}
