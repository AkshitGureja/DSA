#include <stdio.h>
#include <string.h>
#include "deque.h"

/*

The user currently has no option to create a new queue and is given a deque 'Q_front',
by default which is already initialise, ready for the user to push,pop, eject or inject.

Please find any information in the comments at appropriate posititons thorughout the code in the 3 file

*/

int main()
{
    ptr Q_front  = Empty_Queue();

    char function[6];
    char new_line;

    printf("Welcome user, use the functions below with the correct format to run the programme\n");
    printf("In case of any queries, please feel free to contact\n");
    printf("1. push x y (wherex,y are the input)\n");
    printf("2. inject x y (wherex,y are the input)\n");
    printf("3. eject\n");
    printf("4. pop\n");
    printf("5. exit\n\n");

    while(1 == 1)
    {
        scanf("%s", function);

        if(strcmp(function, "exit") == 0)
        {
            exit_queue(Q_front);
            return 0;
        }
        else if(strcmp(function, "pop") == 0)
        {
            Pop(Q_front);
        }
        else if(strcmp(function, "push") == 0)
        {
            double real, imag;
            scanf(" %lf %lf", &real, &imag);
            Push(Q_front, real, imag);
        }
        else if(strcmp(function, "inject") == 0)
        {
            double real, imag;
            scanf(" %lf %lf", &real, &imag);
            inject(Q_front, real, imag);
        }
        else if(strcmp(function, "eject") == 0)
        {
            eject(Q_front);
        }
        else
        {
            printf("If you want to exit, type exit\n");
        }
        
        scanf("%c", &new_line);
    }

    return 0;
}