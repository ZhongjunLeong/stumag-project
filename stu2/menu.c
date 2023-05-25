#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
#include "menu.h"
#define CHARSIZE 40
#define NAMESIZE 32
//extern enum function choose;
void menu()
{
        printf("---------------------------------------\n");
        printf("enter you choose\n");
        printf("1 :student schmea show 2：find student score 3:insert student infomation 4: update student information 5：quit\n");
        printf("---------------------------------------\n");
}
sqlite3 *sqlite_init()
{
        return open_create();

}
sqlite3* open_create(void )
{
         sqlite3 *db ;
        char *errmsg;
        if(sqlite3_open(DATABASE,&db) != SQLITE_OK)
        {
            printf("%s\n",sqlite3_errmsg(db));
            exit(1);
        }
        else
        {
                printf("open DATABASE success.\n");
            
        }
        if(sqlite3_exec(db,"create table stu(id Integer,name char,score Integer);",NULL,NULL,&errmsg) != SQLITE_OK)
        {
            printf("create table:%s\n",errmsg);
        }
        else
            printf("sqlite_exec():success\n");
        return db;
}
void stu_insert(sqlite3 *db)
{
    char *errmsg;
    char sql[CHARSIZE];
    int id;
    int score;
    char name[NAMESIZE];
    if(sqlite_init() == NULL)
    {
        printf("no table\n");
        return ;
    }
    printf("insert id:\n");
    scanf("%d",&id);
    getchar();
    printf("insert name:\n");
    scanf("%s",name);
    getchar();
    printf("insert score:\n");
    scanf("%d",&score);
    sprintf(sql,"insert into stu values(%d,'%s',%d);",id,name,score);
    if(sqlite3_exec(db,sql,NULL,NULL,&errmsg) != SQLITE_OK)
    {
        fprintf(stderr,"sqlite_exec fail:%s\n",errmsg);
        sqlite3_close(db);
        exit(1);
    }
//    sqlite3_close(db);
    
        return ;
}


void info_show_st(sqlite3 *db)
{
    char sql[CHARSIZE];
    char **resultp;
    int nrow;
    int ncolumn;
    char *errmsg;
    int index ;
    int i,j;
    if(db == NULL)
    {
        printf("nothing in table,please insert\n");
        return ;
    }
 //   sql = malloc(sizeof(*sql));
    sprintf(sql,"select * from stu");
    if(sqlite3_get_table(db,sql,&resultp,&nrow,&ncolumn,&errmsg) != SQLITE_OK)
    {
        fprintf(stderr,"get table fail:%s\n",errmsg);
   //     free(sql);
        exit(1);
    }
    index = ncolumn;
    for(i = 0; i < nrow ; i ++)
    {
        for(j = 0 ; j < ncolumn ;j++)
        {
            printf("%s ",resultp[index++]);
        }
        putchar('\n');
    }
    //exit(0);
    return ;

}

void stu_find(sqlite3 *db)
{
    char *errmsg;
    char *sql;
    char **resultp;
    int nrow;
    int ncolumn;
    int id;
    int index = 0;
    int i,j;
    printf("research id:\n");
    scanf("%d",&id);
    getchar();
    sql = malloc(40);
    sprintf(sql,"select * from stu where id = %d;",id);
    if(sqlite3_get_table(db,sql,&resultp,&nrow,&ncolumn,&errmsg) != SQLITE_OK)
    {
        fprintf(stderr,"sqlite_exec fail:%s\n",errmsg);
        free(sql);
        exit(1);
    }
    
    for(j = 0; j < nrow+1 ; j++)
    {
        for(i = 0; i < ncolumn ;i++)
        {
            printf("%s ",resultp[index++]);
        }
        putchar('\n');
    }
      free(sql);
    return ;
}
void stu_update(sqlite3 *db)
{
    char *errmsg;
    char *sql;
    int id,score;
    printf("input update id:\n");
    scanf("%d",&id);
    getchar();
    printf("ipute update score:\n");
    scanf("%d",&score);
    getchar();
    sql = malloc(40);
    sprintf(sql,"update stu set score=%d where id=%d",score,id);
   if(sqlite3_exec(db,sql,NULL,NULL,&errmsg) != SQLITE_OK)
    {
        fprintf(stderr,"sqlite update fail:%s\n",errmsg);
        free(sql);
        exit(1);
    }
   else
       printf("update done\n");
    free(sql);
    return ;
}
