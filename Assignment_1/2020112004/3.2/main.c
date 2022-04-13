#include <stdio.h>
#include "my_stack.h"
#include <string.h>

/*

The user currently has no option to create a new stack and is given a stack 'S',
by default which is already initialized, ready for the user to push and pop.

Please find any information in the comments at appropriate positions throughout the code in the 3 files

*/

int main()
{
    ptr S = Empty_Stack();

    char function[20];
    char newline;
    printf("Welcome user, use the functions below with the correct format to run the programme\n");
    printf("1. push x y (where x,y is the input)\n");
    printf("2. pop\n");
    printf("3. exit\n");
    printf("4. delete_all_terms\n");
    printf("For more information regarding any function or its implementation, refer to the attached files. Thank You\n\n");

    while(1 == 1)
    {   
        scanf("%s", function);

        if(strcmp(function, "exit") == 0)
        {
            exit_programme();
            return 0;
        }
        else if(strcmp(function, "pop") == 0)
        {
            Pop(S);
        }
        else if(strcmp(function, "push") == 0)
        {
            double real, imag;
            scanf(" %lf %lf", &real, &imag);
            Push(S,real, imag);
        }
        else if(strcmp(function, "delete_all_terms") == 0)
        {
            Delete_All_Terms(S);
        }
        else
        {   
            char extra[10];
            scanf("%[^\n]s", function);
            printf("Are you sure you want to exit?\n");
            printf("If you want to exit, type exit\n");
        }

        scanf("%c", &newline);
    }

    return 0;    
}