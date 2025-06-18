#include <stdio.h>
#include <stdlib.h>
#include "stackADT_array.h"

/* Implementation for an interactive interface follows */
void displayMenu() {
	printf("\n=== Stack operations menue === \n");
	printf("1. Push an integer element to stack.\n");
	printf("2. Pop an element from the stack.\n");
	printf("3. Output the Top of the stack\n");
	printf("4. Check if the stack is empty.\n");
	printf("5. Check if the stack is full (only array specific).\n");
	printf("6. Print the contents of the stack.\n");
	printf("7. Empty the stack.\n");
	printf("0: Exit the program.\n");
	printf("\nPlease enter your choice (number).\n");
}

int main() {
	Stack s;
	Initialise(&s);

	int choice, value;

	while(1) {
		displayMenu();
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Try again. Exiting the program ...\n");
            break;
        }

        switch (choice) {
            case 1:
                printf("\nEnter value to push: ");
                if (scanf("%d", &value) != 1) {
                    printf("\nInvalid input.\n");
                    break;
                }
                Push(value, &s);
                break;
            case 2:
                value = Pop(&s);
                if (value != -1)
                    printf("\nPopped value: %d\n", value);
                break;
            case 3:
                value = Top(&s);
                if (value != -1)
                    printf("\nTop of stack: %d\n", value);
                break;
            case 4:
                printf("\nStack is %sempty.\n", isEmpty(&s) ? "" : "not ");
                break;
            case 5:
                printf("\nStack is %sfull.\n", isFull(&s) ? "" : "not ");
                break;
            case 6:
                printStack(&s);
                break;
            case 7:
                makeEmpty(&s);
                printf("Stack cleared.\n");
                break;
            case 0:
                printf("Exiting the program ...\n");
                return 0;
            default:
                printf("\nInvalid choice. Please try again.\n");
		}
	}
	return 0;
}
