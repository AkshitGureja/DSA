#ifndef __COMPLEX_H
#define __COMPLEX_H

typedef struct complex_num comp;
typedef struct complex_num *ptr;

typedef double Data_Type;

struct complex_num
{
    Data_Type num;
    ptr Next;
};

//creates the node for the term corresponding to each dimension and returns pointer to that term
ptr InitComp(Data_Type N);

// creates the dummy node for the complex_num, acts as head pointer and return the pointer
ptr EmptyList();

// insert element into the linked list of the complex number whose head ptr is passed
void insert_element(ptr A, Data_Type N);

//prints the complex number of n-dimensions
void print_list(ptr C);

// free the memory of the complex number
void free_list(ptr C);

// operations that can be performed on the input
ptr addition(ptr A, ptr B);
ptr subtract(ptr A, ptr B);
Data_Type modulus(ptr A);
Data_Type dot_product(ptr A, ptr B);

#endif
