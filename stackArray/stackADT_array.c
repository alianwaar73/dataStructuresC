#include <stdio.h>
#include "stackADT_array.h"

void Initialise(Stack* s) {
	/* Key implementation difference from the 
	 * linked-list approach. An empty stack contains
	 * -1 as the TopOfStack. */
	s->top = -1;
}

int isEmpty(Stack* s) {
	return s->top == -1;
}

/* Only relevant in array-based approach */
int isFull(Stack* s) {
	return s->top == MAX_STACK_SIZE - 1;
}

void Push(int element, Stack* s) {
	if(isFull(s)) {
		printf("[DEBUG:] The stack is full! Cannot push %d\n", element);
		return;
	}
	/* First increment the top of the stack index and
	 * then Push the incoming element */
	s->data[++(s->top)] = element;
}

int Pop(Stack* s) {
	if(isEmpty(s)) {
		printf("[DEBUG:] Nothing to Pop, the stack is empty!\n");
		return -1;
	}
	/* Return, or Pop, the element and then decrement
	 * the Top of the stack */
	return s->data[(s->top)--];
}

int Top(Stack* s) {
	if(isEmpty(s)) {
		printf("[DEBUG:] Nothing at Top, the stack is empty!\n");
		return -1;
	}
	return s->data[s->top];
}

void makeEmpty(Stack* s) {
	/* Much less cluttered and compact as compared to
	 * its linked-list counter-part. No need for memory
	 * management! */
	s->top = -1;
}

void printStack(Stack* s) {
	if(isEmpty(s)) {
		printf("[DEBUG:] Nothing to print, the stack is empty!\n");
		return;
	}
	printf("Stack contents from top to bottom: \n");
	for (int i = s->top; i >=0; i--) {
		printf("%d\n", s->data[i]);
	}
}
