#include <stdio.h>
#include "polynomial.h"
#include <string.h>
#include <assert.h>
#include <ctype.h>

/*

------------------------------------------------------

Welcome user, the format of the functions is exactly as given in the quetion\
For any queries, please feel free to contact

The user also has an option to have the two polynomials given in the sample test case

*/

ptr A_to_Z[26];

int main()
{
    char function[30];
    char ch, x, y, z;
    long int exponent;
    double coeff;
    int index;
    char new_line;

    for(int i = 0; i < 26;i++)
    {
        A_to_Z[i] = NULL;
    }

    printf("Welcome user, use the folllowing functions to play with polynomials\n");
    printf("For example to run functions on polynomial A, use the following format\n\n");

    printf("1. AddPolynomials A B C \n");
    printf("2. SubtractPolynomials A B C \n");
    printf("3. AddTerm Poly A exponent coeff \n");
    printf("4. DeleteTermByExponent A exponent \n");
    printf("5. DeleteAllTerms A \n");
    printf("6. DeletePoly A \n");
    printf("7. PrintPoly A \n");
    printf("8. GetMiddle A \n");
    printf("9. GetQuartile A int x\n\n");

    char yes_or_no;
    printf("Do you want the polynomial given in the sample test case (Y/N): ");
    scanf("%c", &yes_or_no);
    if(toupper(yes_or_no) == 'Y')
    {
        A_to_Z[0] = Empty_Poly();
        A_to_Z[1] = Empty_Poly();
        AddTerm_internally(A_to_Z[0],4,5);
        AddTerm_internally(A_to_Z[0],3,4);
        AddTerm_internally(A_to_Z[0],1,2);
        AddTerm_internally(A_to_Z[0],0,7);

        AddTerm_internally(A_to_Z[1],3,-7.2);
        AddTerm_internally(A_to_Z[1],2,4);
        AddTerm_internally(A_to_Z[1],0,-4);

        printf("You are good to go\n");
    }

    while (1 == 1)
    {   
        scanf("%s", function);
        //printf("%s", function);
    
        if (strcmp(function, "AddTerm") == 0)
        {
            scanf(" %c %ld %lf", &ch, &exponent, &coeff);

            int n = (int)ch - 65;
            //printf("%d %c", n, ch);

            if (A_to_Z[n] == NULL)
            {
                A_to_Z[n] = Empty_Poly();
            }
            AddTerm(A_to_Z[n], exponent, coeff);
        }
        else if (strcmp(function, "PrintPoly") == 0)
        {
            scanf(" %c", &ch);
            int n = (int)ch - 65;
            //printf("%d\n", n);
            if(A_to_Z[n] == NULL)
            {
                printf("Polynomial does not exist\n");
            }
            else
            {
                print_poly(A_to_Z[n]);
            }
        }
        else if (strcmp(function, "AddPolynomials") == 0)
        {
            scanf(" %c %c %c", &x, &y, &z);

            int a = (int)x - 65;
            int b = (int)y - 65;
            int c = (int)z - 65;

            assert(A_to_Z[a] != NULL);
            assert(A_to_Z[b] != NULL);

            if (A_to_Z[c] == NULL)
            {
                A_to_Z[c] = Empty_Poly();
            }
            AddPolynomials(A_to_Z[a], A_to_Z[b], A_to_Z[c]);
        }
        else if (strcmp(function, "DeleteAllTerms") == 0)
        {
            scanf(" %c", &ch);
            DeleteAllTerms(A_to_Z[(int)ch - 65]);
        }
        else if (strcmp(function, "DeleteTermByExponent") == 0)
        {
            scanf(" %c %ld", &ch, &exponent);
            DeleteTermByExponent(A_to_Z[(int)ch - 65], exponent);
        }
        else if (strcmp(function, "SubtractPolynomials") == 0)
        {
            scanf(" %c %c %c", &x, &y, &z);

            int a = (int)x - 65;
            int b = (int)y - 65;
            int c = (int)z - 65;

            assert(A_to_Z[a] != NULL);
            assert(A_to_Z[b] != NULL);
            if (A_to_Z[c] == NULL)
            {
                A_to_Z[c] = Empty_Poly();
            }
            SubtractPolynomials(A_to_Z[a], A_to_Z[b], A_to_Z[c]);
        }
        else if (strcmp(function, "GetMiddle") == 0)
        {
            scanf(" %c", &ch);
            assert(A_to_Z[(int)ch - 65] != NULL);

            ptr P = GetMiddle(A_to_Z[(int)ch - 65]);

            if(P!= NULL)
            {
                printf("%lf*x^%ld\n", P->coeff, P->expo);
            }
        }
        else if (strcmp(function, "GetQuartile") == 0)
        {
            scanf(" %c %d", &ch, &index);
            assert(A_to_Z[(int)ch - 65] != NULL);

            ptr P = GetQuartile(A_to_Z[(int)ch - 65], index);
            if(P!= NULL)
            {
                printf("%lf*x^%ld\n", P->coeff, P->expo);
            }
        }
        else if (strcmp(function, "DeletePoly") == 0)
        {
            scanf(" %c", &ch);
            DeletePoly(A_to_Z[(int)ch - 65]);
            A_to_Z[(int)ch - 65] = NULL;
        }
        else
        {
            printf("Invalid function input, try again\n");
            scanf("%[^\n]s", function);
            printf("Do you want to exit (Y/N) :  ");
            scanf("%c", &new_line);
            scanf("%c", &ch);
            
            if(ch == 'N')
                continue;

            for(int i = 0; i < 26;i++)
            {
                if(A_to_Z[i] != NULL)
                {
                    DeletePoly(A_to_Z[i]);
                }
            }  
            break;
        }
        scanf("%c", &new_line);

    }
    return 0;
}