#include <stdio.h>
#include "menu.h"

extern enum funtion choose;
int main(int argc, char  **argv)
{

    struct score *s = NULL;    
  //  s->id = 100;
    while(1)
    {
        menu();
        scanf("%u\n",&choose);
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
                break;
            default:
                break;
        }
    
    }
    return 0;
}
