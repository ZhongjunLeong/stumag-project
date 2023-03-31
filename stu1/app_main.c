#include <stdio.h>
#include "menu.h"
#include <stdlib.h>
//extern enum funtion choose;
int main(int argc, char  **argv)
{

    struct score *s = NULL;
	int choose;    
  //  s->id = 100;
    while(1)
    {
        menu();
        scanf("%d",&choose);
        switch(choose)
        {
            case student_info:
                    printf("enter student info\n");
                    stu_info(s);

                //func1
                break;
            case student_find:
                    printf("enter student id :\n");
                  //  scanf("%d\n",&s->id);
                    stu_find(100);
                //fun2
                break;
            case quit:
                //fun3
                exit(1);
            default:
                break;
        }
    
    }
    return 0;
}
