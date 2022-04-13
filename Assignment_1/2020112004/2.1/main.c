#include <stdio.h>
#include "singly_linked_list.h"
#include <string.h>
#include <assert.h>
#include <ctype.h>

/*

Please find any information in the comments at appropriate positions throughout the code in the files

*/

int main()
{
    int element;
    char new_line;
    char list;
    char function[20];

    ptr A_to_Z[26];
    for(int i = 0; i < 26;i++)
    {
        A_to_Z[i] = NULL;
    }

    printf("Welcome user, use the functions below with the correct format to run the programme\n");
    printf("The linked list can be named from A to Z only.\n");
    printf("1. InsertFront(linked_list, int x) -- to insert at front of list\n");
    printf("2. InsertLast(linked_list, int x) -- to insert at rear end of list\n");
    printf("3. FindLast(linked_list, int x)\n");
    printf("4. DeleteAll(linked_list, int x)\n");
    printf("5. exit(0,0) -- to exit the programme\n\n");


    while(1==1)
    {
        scanf("%[^(]s", function);
        scanf("(%c, %d)", &list, &element);
        int n = (int)list - 65;

        if(strcmp(function, "FindLast") == 0)
        {
            int position = FindLast(A_to_Z[n], element);
            printf("%d\n", position);
        }
        else if(strcmp(function, "DeleteAll") == 0)
        {
            assert(A_to_Z[n] != NULL);
            Delete_All(A_to_Z[n], element);
        }
        else if(strcmp(function, "InsertFront") == 0)
        {
            if(A_to_Z[n] == NULL)
            {
                A_to_Z[n] = EmptyList();
            }
            insert_element_front(A_to_Z[n], element);
        }
        else if(strcmp(function, "InsertLast") == 0)
        {
            if(A_to_Z[n] == NULL)
            {
                A_to_Z[n] = EmptyList();
            }
            insert_element_last(A_to_Z[n], element);
        }
        else if(strcmp(function, "exit") == 0)
        {
            for(int i = 0; i < 26;i++)
            {   
                if(A_to_Z[i] != NULL)
                {
                    free_list(A_to_Z[i]);
                }
            }
            printf("Thank you so much\n");
            return 0;
        }
        else
        {
            printf("To exit, type exit(0,0)\n");
        }
        
        scanf("%c", &new_line);
    }
    return 0;
}
