#ifndef STACK_ARRAY_H
#define STACK_ARRAY_H

/* This is an array specific setting. No need to pre-specify
 * the maximum size as we observed in the linked-list approach
 * . Change the specified number (100) in case needed. */
#define MAX_STACK_SIZE 100

typedef struct {
	/* The first element an the array. 
	 * An absence of pointers can be noticed 
	 * in comparison to the linked-list approach. */
	int data[MAX_STACK_SIZE];
	int top;
} Stack;

/* Array-specific function declarations follow.
 * Initialise is unique to the array approach.
 * !Also worth noticing is the absence of any headers. 
 * !For Initialise, we provide a pointer to the a
 * stack structure. */
void Initialise(Stack* s);
int isEmpty(Stack* s);
int isFull(Stack* s);
void Push(int element, Stack* s);
int Pop(Stack* s);
int Top(Stack* s);
void makeEmpty(Stack* s);
void printStack(Stack* s);

#endif
