#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
extern enum funtion choose;
int main(int argc, char  **argv)
{

    struct score *s = NULL;    
    int id;
//   extern enum funtion choose;
    while(1)
    {
        menu();
        scanf("%u",&choose);
        switch(choose)
        {
            case student_info:
                    printf("enter student info\n");
                    stu_info(s);

                //func1
                break;
            case student_find:
                    printf("enter student id :\n");
                    scanf("%d",&id);
                    stu_find(id);
                //fun2
                break;
            case quit:
                //fun3
                exit(1);
            default:
                   printf("please enter 1-3number\n");
                break;
        }
    
    }
    return 0;
}
