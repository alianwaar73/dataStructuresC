#include <stdio.h>
#include <stdlib.h>
#include "stackADT_linked.h"

void initializeStack(Stack* s) {
    s->top = NULL;
}

int isEmpty(Stack* s) {
    return s->top == NULL;
}

void Push(int element, Stack* s) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed during push.\n");
        exit(EXIT_FAILURE);
    }
    newNode->element = element;
    newNode->next = s->top;
    s->top = newNode;
    printf("Element %d pushed onto stack successfully.\n", element);
}

int Pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack underflow! Cannot perform pop on an empty stack.\n");
        return -1;
    }

    Node* temp = s->top;
    int poppedElement = temp->element;
    s->top = temp->next;
    free(temp);
    printf("Element %d popped from stack successfully.\n", poppedElement);
    return poppedElement;
}

int Top(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty. No top element present.\n");
        return -1;
    }
    return s->top->element;
}

void makeEmpty(Stack* s) {
    while (!isEmpty(s)) {
        Pop(s);
    }
    printf("Stack has been cleared and is now empty.\n");
}

void printStack(Stack* s) {
    Node* current = s->top;
    printf("Current stack contents (top to bottom): ");
    if (isEmpty(s)) {
        printf("Stack is empty.\n");
        return;
    }

    while (current != NULL) {
        printf("%d ", current->element);
        current = current->next;
    }
    printf("\n");
}

