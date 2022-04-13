#ifndef __POLY_H
#define __POLY_H

typedef struct PolyTerm* ptr;
typedef struct PolyTerm* Poly;
typedef struct PolyTerm PTerm;

struct PolyTerm
{
    unsigned long int expo;
    double coeff;
    ptr Next;
};

//create node for the new term
ptr Make_Term(unsigned int E, double N);

//initialises a new polynomial by creating a dummy node
ptr Empty_Poly();

void AddPolynomials(ptr A, ptr B, ptr C);
void SubtractPolynomials(ptr A, ptr B, ptr C);
void DeleteTermByExponent(ptr P, unsigned long int exponent);
void AddTerm(ptr P, unsigned int E, double N);

ptr GetMiddle(ptr P);
ptr GetQuartile(ptr P, int x); // gives the term corresponding to ceil(x*n/100)

void DeleteAllTerms(ptr P); //Delete all terms (make all coefficients equal to 0)
void DeletePoly(ptr P); //Delete the polynomial (remove its existence)
void print_poly(ptr P);

//if the user wants an example which is ready to be worked on
// the polynomial given to the user will be the one mentioned in the givensample test case
// the only major difference is that the AddTerm function prints "Done" after every step
// whereas this function does not print Done for better user interface
void AddTerm_internally(ptr P, unsigned int E, double N);


#endif