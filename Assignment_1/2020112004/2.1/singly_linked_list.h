#ifndef __SLL_H
#define __SLL_H

#include "IntElement.h"

typedef struct Node* ptr;
typedef struct Node Node;

struct Node
{
    ElementType num;
    ptr Next;
};

//Creates the node
ptr Make_Node(ElementType N);

//Initialises the linked list, makes a dummy node.
ptr EmptyList();

//prints the linked list
void print_list(ptr A);

//insert element at front of the linked list
void insert_element_front(ptr A, ElementType N);

//insert element at the rear end of the linked list
void insert_element_last(ptr A, ElementType N);

// Finds last occurence of the element N in the list and returns its position
int FindLast(ptr A, ElementType N);

// Deletes all elements of the value N in the linked list.
void Delete_All(ptr A, ElementType N);

// Removes the existence of the linked list
void free_list(ptr A);

#endif
