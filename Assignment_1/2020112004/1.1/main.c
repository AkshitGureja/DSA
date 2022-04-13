#include <stdio.h>
#include <string.h>
#include "complex.h"

/* --------------------- Please compile using -lm as the file uses math.h --------------------- */
// feel free to contact in case of any query

ptr A;
ptr B;
void two_complex_num(int dimensions); // function for scanning two rows of inputs
void one_complex_num(int dimensions); // function for scanning one row of input.

int main()
{
    char function[3]; // there are 4 given function or operations -- ADD, MOD, SUB, DOT
    scanf("%s", function);

    int dimensions;
    scanf("%d", &dimensions);

    A = EmptyList(); // initialise complex number A
    B = EmptyList(); // initialise complex number B

    if (strcmp(function, "ADD") == 0)
    {
        two_complex_num(dimensions);
        ptr C = addition(A, B);
        print_list(C);
    }
    else if (strcmp(function, "SUB") == 0)
    {
        two_complex_num(dimensions);
        ptr C = subtract(A, B);
        print_list(C);
    }
    else if (strcmp(function, "DOT") == 0)
    {
        two_complex_num(dimensions);
        printf("%.2lf\n", dot_product(A, B));
    }
    else if (strcmp(function, "MOD") == 0)
    {
        one_complex_num(dimensions);
        printf("%.2lf\n", modulus(A));
    }
    else
    {
        printf("Invalid function input, please enter a valid function\n");
    }

    //free the memory of both the complex numbers
    free_list(A);
    free_list(B);

    return 0;
}

void two_complex_num(int dimensions)
{
    for (int i = 0; i < dimensions; i++)
    {
        Data_Type a;
        scanf("%lf", &a);
        insert_element(A, a);
    }

    for (int j = 0; j < dimensions; j++)
    {
        Data_Type b;
        scanf("%lf", &b);
        insert_element(B, b);
    }
    return;
}

void one_complex_num(int dimensions)
{
    for (int i = 0; i < dimensions; i++)
    {
        Data_Type a;
        scanf("%lf", &a);
        insert_element(A, a);
    }

    return;
}