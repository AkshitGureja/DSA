#include "singly_linked_list.h"
#include <stdio.h>
#include <assert.h>
#include <malloc.h>


ptr Make_Node(ElementType N)
{
    ptr P = (ptr)malloc(sizeof(Node));
    assert(P!= NULL);

    P->num = N;
    P->Next = NULL;
    return P;
}

//Initialises the linked list by creating a dummy node
ptr EmptyList()
{
    ptr P = Make_Node(0);
    return P;
}

// finds last occurence of N and returns its position as an integer
int FindLast(ptr A, ElementType N)
{
    assert(A!=NULL);
    int count = 0;
    int position = -1;
    while(A->Next != NULL)
    {
        if(A->Next->num == N)
            position = count;

        count++;
        A = A->Next;
    }
    return position;
}

void Delete_All(ptr A, ElementType N)
{
    assert(A!=NULL);
    ptr P = A;
    
    while(A->Next != NULL)
    {
        if(A->Next->num == N)
        {
            ptr C = A->Next->Next;
            ptr K = A->Next;
            free(K);
            A->Next = C;
        }
        else
        {
            A = A->Next;
        }
    }
    print_list(P);
    return;
}

void free_list(ptr A)
{
    ptr Z = A;
    while(Z != NULL)
    {
        ptr tmp = Z->Next;
        free(Z);
        Z = tmp;
    }
    return;
}

void print_list(ptr A)
{
    assert(A!=NULL);
    ptr List = A->Next;
    while(List->Next != NULL)
    {
        printf("%d--->", List->num);
        List = List->Next;
    }
    printf("%d\n", List->num);

    printf("End of List. thanks for cooperating\n");
}

void insert_element_last(ptr A, ElementType N)
{
    ptr C = Make_Node(N);
    ptr Z = A;

    if(A->Next == NULL)
    {
        printf("Done\n");
        A->Next = C;
        C->num = N;
    }
    else
    {
        printf("Yes\n");
        while(Z->Next != NULL)
        {
            Z = Z->Next;
        }
        Z->Next = C;
    }
    print_list(A);
}

void insert_element_front(ptr A, ElementType N)
{
    ptr C = Make_Node(N);
    ptr Z = A;

    if(A->Next == NULL)
    {
        A->Next = C;
        C->num = N;
    }
    else
    {
        C->Next = A->Next;
        A->Next = C;
    }
    print_list(A);
    return;
}

