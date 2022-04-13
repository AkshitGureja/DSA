#include "my_stack.h"
#include <stdio.h>
#include <malloc.h>
#include <assert.h>

ptr default_stack;

//creates a new node and returns the pointer to it
ptr Make_term(Data_Type A, Data_Type B)
{
    ptr S;
    S = (ptr)(malloc(sizeof(struct my_stack)));
    assert(S != NULL);

    S->real = A;
    S->imag = B;
    S->Next = NULL;

    return S;
}

//initialises the stack, by creating a dummy node and acts as the head pointe
ptr Empty_Stack()
{
    ptr S = Make_term(0,0);
    default_stack = S;
    return S;
}

void Push(ptr S, Data_Type A, Data_Type B)
{
    ptr T = Make_term(A, B);
    ptr K = S;
    
    if(K->Next == NULL) // if the stack is currently empty
    {
        T->Next = NULL;
        K->Next = T;
    }
    else
    {
        T->Next = K->Next;
        K->Next = T;
    }
    print_stack(S);

    return;
}

void Pop(ptr S)
{
    if(S->Next == NULL) // if the stack is empty
    {
        printf("The Stack Is Empty\n");
        return;
    }

    ptr K = S;
    ptr tmp = K->Next;
    K->Next = K->Next->Next;
    free(tmp);
    print_stack(S);    

    return;
}

void exit_programme()
{
    //delete the stack to prevent any memory leak
    Delete_Stack(default_stack);
    
    printf("\n");
    return;
}

void print_stack(ptr S)
{
    ptr K = S->Next;
    while(K!=NULL)
    {
        printf("{%.2lf %.2lf} ", K->real, K->imag);
        K = K->Next;
    }
    printf("\n");

    return;
}

void Delete_All_Terms(ptr S)
{
    ptr K = S->Next;
    while(S->Next != NULL)
    {
        S->Next = K->Next;
        free(K);
        K = K->Next;
    }   
    printf("Done\n");
    return;
}

void Delete_Stack(ptr S)
{
    ptr Z = S;
    while(Z != NULL)
    {
        ptr tmp = Z->Next;
        free(Z);
        Z = tmp;
    }
    S = NULL;
}