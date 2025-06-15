#include <stdio.h>
#include <stdlib.h>

/* The following Node ADT is a singly-linked list with an
 * integer element and a pointer to the next element
 * location. */
typedef struct Node {
	int element;
	struct Node* next;
} Node;

typedef struct {
	Node* top;
} Stack;

/* Stack initialisation */
void initialiseStack(Stack* s) {
	s->top = NULL;
}

/* Function to determine if the stack is empty */
int isEmpty(Stack* s) {
	return s->top == NULL;
}

/* Function to push an element onto the stack */
void Push(Stack* s, int element) {
	Node* newNode = (Node*) malloc(sizeof(Node));

	if(!newNode) {
		printf("Fatal: Memory allocation failed during Push \n");
		exit(EXIT_FAILURE);
	}
	newNode->element = element;
	newNode->next = s->top;
	/* New head of the stack s */
	s->top = newNode;
	printf("[DEBUG:] Pushed %d onto the stack.", element);
}

/* Function to pop an element from the stack */
int Pop(Stack* s) {
	if(isEmpty(s)) {
		printf("[DEBUG:] Stack UNDERFLOW! Cannot POP!");
		return -1;
	}
	
	Node* temp = s->top;
	int element = temp->element;
	s->top = temp->next;
	free(temp);
	printf("[DEBUG:] Element: %d POPped from stack.", element);
	return element;
}

/* Function Top returns the element on top of the stack if it is not empty */

int Top(Stack* s) {
	if(isEmpty(s)) {
		printf("[DEBUG:] Nothing found at the TOP of the stack. The stack is empty!");
		return -1;
	}
	printf("[DEBUG:] Element: %d found at the TOP of the stack", s->top->element);
	return s->top->element;
}

/* Function to empty the stack */
void makeEmpty(Stack* s) {
	while(!isEmpty(s)) {
		Pop(s);
	}
	printf("[DEBUG:] Stack has been emptied.\n");
}

/* Function to print out the entire stack as it stands */
void printStack(Stack* s) {
	Node* current = s->top;
	if(!current) {
		printf("[DEBUG:] Nothing to print, the stack is empty!\n");
	}
	while(current) {
		printf("%d", current->element);
		current = current->next;
	}
}

int main() {
	Stack myStack;
	initialiseStack(&myStack);
	/* For user prompts */
	int choice, element;
	printf("\n\n>>> The stack ADT with linked-list implementation <<< \n\n");
	
	while(1) {
		printf("\n== Choose an operation to perform on the stack == \n");
		printf("1. Push an integer element to the stack \n");
		printf("2. Pop an element from the stack \n");
		printf("3. Show Top of the stack \n");
		printf("4. Check to determine if the stack is empty. \n");
		printf("5. Empty the entire stack. \n");
		printf("6. Print the entire stack. \n");
		printf("0. Exit the program. \n");

		printf("\n> Enter your choice: \n");
		
		/* For when the user interacts with our program for the first time. */
		if(scanf("%d", &choice) != 1) break;

		switch (choice) {
			case 1:
				printf("Enter the value of the element to push onto the stack: ");
				scanf("%d", &element);
				Push(&myStack, element);
				break;
			case 2:
				Pop(&myStack);
				break;
			case 3:
				Top(&myStack);
				break;
			case 4:
				printf("The stack is %sempty.\n", isEmpty(&myStack) ? "" : "not ");
				break;
			case 5:
				makeEmpty(&myStack);
				break;
			case 6:
				printStack(&myStack);
				break;
			case 0:
				/* A clean exit from the program */
				makeEmpty(&myStack);
				printf("Exiting the program.\n");
				return 0;
			default:
				printf("Invalid choice. Try again. \n");
		}
	}
	return 0;
}
