#ifndef __STACK_LINKEDLIST_H
#define __STACK_LINKEDLIST_H

typedef struct my_stack* ptr;
typedef struct my_stack* stack;
typedef double Data_Type;

struct my_stack
{
    Data_Type real;
    Data_Type imag;
    ptr Next;    
};

//creates the node for the new term
ptr Make_term(Data_Type A, Data_Type B);

//creates the dummy node for the linked list, acts as the head pointer
ptr Empty_Stack();

// functions which can be performed on the stack
void Push(ptr S, Data_Type A, Data_Type B);
void Pop(ptr S);

// exit the programme
void exit_programme();

//prints the stack
void print_stack(ptr S);

//deletes all the terms, leaves the header
//there is no need to delete the terms before exiting, the exit function handles it 
void Delete_All_Terms(ptr S);

//removes the existence of the stack
void Delete_Stack(ptr S);

#endif