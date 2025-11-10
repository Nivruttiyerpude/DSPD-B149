#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

int stack[MAX];
int top = -1;

// Function prototypes
void push(int element);
int pop();
void display();
void checkPalindrome();
int isEmpty();
int isFull();

int main() {
    int choice, element;

    while (1) {
        printf("\n STACK MENU \n");
        printf("1. Push an Element onto Stack\n");
        printf("2. Pop an Element from Stack\n");
        printf("3. Check Palindrome using Stack\n");
        printf("4. Demonstrate Overflow / Underflow\n");
        printf("5. Display Stack\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter element to push: ");
            scanf("%d", &element);
            push(element);
            break;

        case 2:
            element = pop();
            if (element != -1)
                printf("Popped element: %d\n", element);
            break;

        case 3:
            checkPalindrome();
            break;

        case 4:
            // Demonstrate Overflow and Underflow (limited to prevent console flooding)
            printf("\n--- Overflow Demonstration ---\n");
            for (int i = 0; i < 5; i++)
                push(i);
            push(999); // show overflow once

            printf("\n--- Underflow Demonstration ---\n");
            for (int i = 0; i < 5; i++)
                pop();
            pop(); // show underflow once
            break;

        case 5:
            display();
            break;

        case 6:
            printf("Exiting program...\n");
            return 0;

        default:
            printf("Invalid choice! Please try again.\n");
        }
    }
}

// Check if stack is full
int isFull() {
    return top == MAX - 1;
}

// Check if stack is empty
int isEmpty() {
    return top == -1;
}

// Push operation
void push(int element) {
    if (isFull()) {
        printf("Stack Overflow! Cannot push %d\n", element);
        return;
    }
    stack[++top] = element;
    printf("%d pushed onto stack.\n", element);
}

// Pop operation
int pop() {
    if (isEmpty()) {
        printf("Stack Underflow! Cannot pop.\n");
        return -1;
    }
    return stack[top--];
}

// Display stack contents
void display() {
    if (isEmpty()) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Current Stack : ");
    for (int i = top; i >= 0; i--)
        printf("%d ", stack[i]);
    printf("\n");
}

// Palindrome check using stack logic
void checkPalindrome() {
    char str[100];
    int i, len;
    int tempTop = -1;
    char tempStack[100];

    printf("Enter a string to check palindrome: ");
    scanf(" %s", str);  // Note: space before %s to handle newline

    len = strlen(str);

    // Push all characters into temporary stack
    for (i = 0; i < len; i++)
        tempStack[++tempTop] = tolower(str[i]);

    // Compare characters while popping
    for (i = 0; i < len; i++) {
        if (tolower(str[i]) != tempStack[tempTop--]) {
            printf("Not a Palindrome.\n");
            return;
        }
    }

    printf("It is a Palindrome!\n");
}
