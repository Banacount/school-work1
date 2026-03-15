#include <stdio.h>
#include <stdbool.h>
#define MAX 20

int top  = -1;
int stack[MAX];
void displayMenu();
int push(int value);
int pop();
int peek();
int displayStack();

int main () {
    int response = 0;
    displayMenu();

    while (true) {
        printf("Enter action 1/2/3/4: ");
        scanf("%d", &response);

        if (response == 1) {
            int value;
            printf("Enter value: ");
            scanf("%d", &value);
            push(value);
        } else if (response == 2) {
            pop();
        } else if (response == 3) {
            peek();
        } else if (response == 4) {
            displayStack();
        } else if (response == 5) {
            printf("Goodbye! hehe\n");
            break;
        } else {
            printf("Invalid command..\n");
            response = 0;
            displayMenu();
        }
    }

    return 0;
}

void displayMenu() {
    printf("-- Actions menu --\n");
    printf("[ 1 ] - Push.\n");
    printf("[ 2 ] - Pop.\n");
    printf("[ 3 ] - Peek.\n");
    printf("[ 4 ] - Display stack.\n");
    printf("[ 5 ] - Exit.\n");
}

int push(int value) {
    if (top >= MAX-1) {
        printf("Stack overflow..\n");
        return 1;
    }
    
    top++;
    stack[top] = value;
    return 0;
}

int pop() {
    if (top < 0) {
        printf("Stack is empty..\n");
        return 1;
    }

    printf("Removing stack value [ %d ].\n", stack[top]);
    top--;
    return 0;
}

int peek() {
    if (top < 0) {
        printf("Stack is empty..\n");
        return 1;
    }

    printf("Latest stack is [ %d ].\n", stack[top]);
    return 0;
}

int displayStack() {
    if (top < 0) {
        printf("Stack is empty..\n");
        return 1;
    }

    for (int i = top; i >= 0; i--) {
        printf("[ %d ]\n", stack[i]);
    }

    return 0;
}
