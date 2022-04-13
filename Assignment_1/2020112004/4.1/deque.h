#ifndef __QUEUE_H
#define __QUEUE_H

typedef struct Node* ptr;
typedef double Data_Type;

struct Node
{
    Data_Type real;
    Data_Type imag;
    ptr Next;
    ptr Prev;
};

//creates the node for the new term
ptr Make_term(Data_Type A, Data_Type B);

//creates the dummy node for the linked list, acts as the head pointer
ptr Empty_Queue();

//functions which can be performed on the deque
void Push(ptr Q_front, Data_Type A, Data_Type B);
void Pop(ptr Q_front);
void inject(ptr Q_front, Data_Type A, Data_Type B);
void eject(ptr Q_front);

//exit the programme
void exit_queue();

//print the deque
void print_queue(ptr Q_front);

//Delete the existence of the queue
void Delete_Queue(ptr Q_front);

#endif
