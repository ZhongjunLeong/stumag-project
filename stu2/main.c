#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
#include "menu.h"
enum funtion
{
    student_info = 1,
    student_find,
    stuinfo_insert,
    stuinfo_update,
    quit
};
enum funtion choose;
int main( )
{//   extern enum funtion choose;
    sqlite3* db;
    db = (sqlite3 *)sqlite_init();
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
  //  sqlite3_close(db);
    return 0;
}
