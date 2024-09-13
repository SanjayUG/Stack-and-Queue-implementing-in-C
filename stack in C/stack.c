
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10

int stack[MAX_SIZE];
int top = -1;

void push(int value) {
    if (top == MAX_SIZE - 1) {
        printf("Stack overflow! Cannot push more elements.\n");
    } else {
        top++;
        stack[top] = value;
        printf("%d pushed into the stack.\n", value);
    }
}

void pop() {
    if (top == -1) {
        printf("Stack underflow! Cannot pop from an empty stack.\n");
    } else {
        printf("Popped element: %d\n", stack[top]);
        top--;
    }
}

void display() {
    if (top == -1) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

int main() {
    int choice, value;

    while (1) {
        printf("\nStack Operations\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to be pushed: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
                break;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } 

    return 0;
}