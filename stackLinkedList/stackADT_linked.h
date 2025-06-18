/* === The header file containing declarations of all the
 * functions === */
#ifndef STACK_LINKED_H
#define STACK_LINKED_H

typedef struct Node {
    int element;
    struct Node* next;
} Node;

typedef struct {
    Node* top;
} Stack;

void initializeStack(Stack* s);
int isEmpty(Stack* s);
void Push(int element, Stack* s);
int Pop(Stack* s);
int Top(Stack* s);
void makeEmpty(Stack* s);
void printStack(Stack* s);

#endif
