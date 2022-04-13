#include <stdio.h>
#include <math.h>
#include <malloc.h>
#include <assert.h>
#include "complex.h"

ptr InitComp(Data_Type N) //returns pointer to the term
{
    ptr C = (ptr)malloc(sizeof(comp));
    assert(C != NULL);

    C->num = N;
    C->Next = NULL;
    return C;
}

ptr EmptyList() //this just gives head pointer
{
    ptr C = InitComp(0);
    return C;
}

void insert_element(ptr A, Data_Type N)
{
    ptr C = InitComp(N);

    if (A->Next == NULL) // if the list is empty, A is the head pointer to the dummy node
    {
        A->Next = C;
        C->num = N;
    }
    else
    {
        C->Next = A->Next;
        A->Next = C;
        C->num = N;
    }
    return;
}

void print_list(ptr C)
{
    ptr List = C->Next;
    while (List->Next != NULL)
    {
        printf("%.2lf ", List->num);
        List = List->Next;
    }
    printf("%.2lf\n", List->num);

    // This message is printed to thank the user for their cooperation.
    printf("End of List. Thanks for cooperating\n");

    //free the memory of the list after printing to ensure no memory leak
    free_list(C);
    return;
}

ptr addition(ptr A, ptr B)
{
    //initialise new complex number C to store the result of addition
    ptr C = EmptyList();

    while (A->Next != NULL)
    {
        Data_Type NUM = A->Next->num + B->Next->num;

        // result of each addition is stored as a new term in the linked list C
        insert_element(C, NUM);
        A = A->Next;
        B = B->Next;
    }
    return C;
}

ptr subtract(ptr A, ptr B)
{
    //initialise new complex number C to store the result of subtraction
    ptr C = EmptyList();

    while (A->Next != NULL)
    {
        Data_Type NUM = A->Next->num - B->Next->num;

        // result of each subtraction is stored as a new term in the linked list C
        insert_element(C, NUM);
        A = A->Next;
        B = B->Next;
    }

    return C;
}

Data_Type modulus(ptr A)
{
    Data_Type NUM = 0;

    while (A->Next != NULL)
    {
        NUM += ((A->Next->num) * (A->Next->num));

        A = A->Next;
    }

    NUM = sqrt(NUM);
    return NUM;
}

Data_Type dot_product(ptr A, ptr B)
{
    Data_Type NUM = 0;

    while (A->Next != NULL)
    {
        NUM += (A->Next->num) * (B->Next->num);

        A = A->Next;
        B = B->Next;
    }

    return NUM;
}

void free_list(ptr C)
{
    ptr Z = C;
    while (Z != NULL)
    {
        ptr tmp = Z->Next;
        free(Z);
        Z = tmp;
    }
}
