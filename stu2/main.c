#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
#include "menu.h"
extern enum funtion choose;
int main( )
{
        sqlite3 *db;
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

       //create a schema 
        if(sqlite3_exec(db,"create table stu(id Integer,name char,score Integer);",NULL,NULL,&errmsg) != SQLITE_OK)
        {
            printf("%s\n",errmsg);
            exit(1);
        }

//   extern enum funtion choose;
    while(1)
    {
        menu();
        scanf("%u",&choose);
        switch(choose)
        {
            case student_info:
                    info_show_st(db);

                //func1
                break;
            case student_find:
                    stu_find(db);
                //fun2
                break;
            case stuinfo_insert:
                    stu_insert(db);
                break;
            case stuinfo_update:
                    stu_update(db);
                break;
            case quit:
                    sqlite3_close(db);
                exit(0);
            default:
                   printf("please enter 1-3number\n");
                break;
        }
    
    }
    return 0;
}
