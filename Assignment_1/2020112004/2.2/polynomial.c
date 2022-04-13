#include "polynomial.h"
#include <malloc.h>
#include <assert.h>
#include <stdio.h>

#define INT_MAX 10000

ptr Make_Term(unsigned int E, double N)
{
    ptr P = (ptr)(malloc(sizeof(PTerm)));
    assert(P!=NULL);

    P->expo = E;
    P->coeff = N;
    P->Next = NULL;

    return P;
}

ptr Empty_Poly()
{
    ptr P = Make_Term(INT_MAX, 0);
    return P;
}

void AddPolynomials(ptr A, ptr B, ptr C)
{
    while(A->Next != NULL)
    {
        AddTerm_internally(C, A->Next->expo, A->Next->coeff);
        A=A->Next;
    }
    while(B->Next != NULL)
    {
        AddTerm_internally(C, B->Next->expo, B->Next->coeff);
        B=B->Next;
    }
    printf("Done\n");
}

void SubtractPolynomials(ptr A, ptr B, ptr C)
{
    while(A->Next != NULL)
    {
        AddTerm_internally(C, A->Next->expo, A->Next->coeff);
        A = A->Next;
    }
    while(B->Next != NULL)
    {
        AddTerm_internally(C, B->Next->expo, (B->Next->coeff)*(-1) );
        B = B->Next;
    }
    printf("Done\n");
}

void DeleteTermByExponent(ptr P, unsigned long int exponent)
{
    while(P->Next != NULL)
    {
        if(P->Next->expo == exponent)
        {
            ptr C = P->Next->Next;
            ptr K = P->Next;
            free(K);
            P->Next = C;
            break;
        }
        P = P->Next;
    }
    printf("Done\n");
}

void AddTerm(ptr P, unsigned int E, double N)
{
    ptr T;
    while((P->Next != NULL) && P->Next->expo > E)
    {
        P = P->Next;
    }

    if((P->Next == NULL) || P->Next->expo <E)
    {
        T = Make_Term(E, N);
        T->Next = P->Next;
        P->Next = T;
    }
    else //P->Next->expo == exponent
    {
        P->Next->coeff += N;
    }
    printf("Done\n");
}

ptr GetMiddle(ptr P)
{
    ptr T = P;
    int num_terms = 0;
    while(P->Next != NULL)
    {
        num_terms++;
        P = P->Next;
    }

    int position = (num_terms+1)/2;

    for(int i =0; i <position;i++)
    {
        T = T->Next;
    }
    return T;
}

ptr GetQuartile(ptr P, int x)
{
    ptr T = P;
    int num_terms = 0;
    while(P->Next != NULL)
    {
        num_terms++;
        P =P->Next;
    }

    if(x > 100)
    {
        printf("The integer should be less than 100\n");
        printf("Try again later\n");
        return NULL;
    }

    float position = ((num_terms)*(x))/100.0;
    int p = position;
    if(p!=position)
    {
        position = p+1;
    }

    for(int i = 0; i <position;i++)
    {
        T = T->Next;
    }
    return T;
}

void print_poly(ptr P)
{

    ptr List = P->Next;
    
    if(List == NULL) 
    {
        printf("Polynomial does not exist\n");
        return;
    }

    while(List->Next != NULL)
    {   
        if(List->coeff != 0)
        {   
            if(List->coeff > 0)
                printf("%.2lf*x^%ld + ", List->coeff, List->expo);
            else 
                printf("(%.2lf*x^%ld) + ", List->coeff, List->expo);
        }
        List = List->Next;
    }

    if(List->coeff != 0)
        printf("%.2lfx^%ld\n",List->coeff, List->expo);
    else 
        printf("0\n");


    printf("End of List. Thanks for cooperating\n");
}

void DeleteAllTerms(ptr P)
{
    while(P->Next != NULL)
    {
        P->Next->coeff = 0;
        P = P->Next;
    }
    printf("Done\n");
}

void DeletePoly(ptr P)
{   
    ptr Z = P;
    while(Z != NULL)
    {
        ptr tmp = Z->Next;
        free(Z);
        Z = tmp;
    }

    printf("Done\n");
    // if(Z == NULL)
    //     printf("Yes\n");
    
    P = NULL;
}   

void AddTerm_internally(ptr P, unsigned int E, double N)
{
    //ptr Z = P;
    ptr T;
    while((P->Next != NULL) && P->Next->expo > E)
    {
        P = P->Next;
    }

    if((P->Next == NULL) || P->Next->expo <E)
    {
        T = Make_Term(E, N);
        T->Next = P->Next;
        P->Next = T;
    }
    else //P->Next->expo == exponent
    {
        P->Next->coeff += N;
    }
    //printf("Done\n");
}

