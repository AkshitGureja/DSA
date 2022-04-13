#include <stdio.h>
#include "deque.h"
#include <malloc.h>
#include <assert.h>

ptr default_queue;
int num_elements;

ptr Make_term(Data_Type A, Data_Type B)
{
    ptr Q = (ptr)(malloc(sizeof(struct Node)));
    assert(Q!=NULL);

    Q->real = A;
    Q->imag = B;
    Q->Next = NULL;
    Q->Prev = NULL;
}

ptr Empty_Queue()
{
    ptr Q = Make_term(0,0);
    default_queue = Q;
    return Q;
}

void Push(ptr Q_front, Data_Type A, Data_Type B)
{
    if(Q_front->Next == NULL)
    {
        ptr T = Make_term(A,B);
        Q_front->Next = T;
        T->Next = Q_front;
        Q_front->Prev = T;
        T->Prev = Q_front;
    }
    else
    {
        ptr T = Make_term(A,B);
        T->Next = Q_front->Next;
        Q_front->Next->Prev = T;
        Q_front->Next = T;
        T->Prev = Q_front;
    }
    
    num_elements++;
    print_queue(Q_front);
    return;
}

void Pop(ptr Q_front)
{
    if(Q_front->Next == NULL || num_elements == 0)
    {
        printf("The deque is Empty\n");
        return;
    }
    ptr tmp = Q_front->Next;

    Q_front->Next = Q_front->Next->Next;
    Q_front->Next->Prev = Q_front;
    free(tmp);

    num_elements--;
    print_queue(Q_front);
    return;
}

void inject(ptr Q_front, Data_Type A, Data_Type B)
{
    if(Q_front->Next == NULL)
    {
        Push(Q_front, A, B);
        return;
    }

    ptr T = Make_term(A,B);

    T->Prev = Q_front->Prev;
    Q_front->Prev->Next = T;
    Q_front->Prev = T;
    T->Next = Q_front;

    num_elements++;
    print_queue(Q_front);
    return;
}

void eject(ptr Q_front)
{
    if(Q_front->Next == NULL || num_elements == 0)
    {
        printf("The deque is Empty\n");
        return;
    }

    ptr tmp = Q_front->Prev;
    Q_front->Prev = Q_front->Prev->Prev;
    free(tmp);
    Q_front->Prev->Next = Q_front;

    num_elements--;
    print_queue(Q_front);
    return;
}

void exit_queue()
{
    Delete_Queue(default_queue);
    return;
}

void print_queue(ptr Q_front)
{
    ptr K = Q_front->Next;

    for(int i = 0; i < num_elements;i++)
    {
        printf("{%.1lf %.1lf} ", K->real, K->imag);
        K = K->Next;
    }
    printf("\n");
    return;
}

void Delete_Queue(ptr Q_front)
{
    ptr Z = Q_front->Next;
    while(Q_front != Z->Next)
    {
        ptr tmp = Z->Next;
        free(Z);
        Z = tmp;
    }
    free(Z);
    printf("Done\n");
    // if(Z==NULL)
    //     printf("Yes\n");

    Q_front = NULL;
    return;
}