#include <stdio.h>
#include <stdlib.h>
#include "stackADT_linked.h"

void displayMenu() {
    printf("\nStack ADT - Linked List Implementation\n");
    printf("1. Push an element\n");
    printf("2. Pop the top element\n");
    printf("3. View the top element\n");
    printf("4. Check if stack is empty\n");
    printf("5. Print the stack\n");
    printf("6. Clear the stack\n");
    printf("7. Exit the program\n");
    printf("Enter your choice: ");
}

int main() {
    Stack s;
    initializeStack(&s);

    int choice, value;

    while (1) {
        displayMenu();
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting.\n");
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter an integer value to push onto the stack: ");
                if (scanf("%d", &value) != 1) {
                    printf("Invalid input. Please enter an integer.\n");
                    break;
                }
                Push(value, &s);
                break;
            case 2:
                Pop(&s);
                break;
            case 3:
                value = Top(&s);
                if (value != -1)
                    printf("Top element of the stack is: %d\n", value);
                break;
            case 4:
                if (isEmpty(&s))
                    printf("Stack is currently empty.\n");
                else
                    printf("Stack is not empty.\n");
                break;
            case 5:
                printStack(&s);
                break;
            case 6:
                makeEmpty(&s);
                break;
            case 7:
                makeEmpty(&s);
                printf("Exiting the program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please select a valid option from the menu.\n");
        }
    }

    return 0;
}

