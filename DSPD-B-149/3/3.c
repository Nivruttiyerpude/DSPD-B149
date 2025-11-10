#include <stdio.h>
#define MAX 5

char queue[MAX];
int front = -1, rear = -1;

// Check if queue is full
int isFull() {
    return rear == MAX - 1;
}

// Check if queue is empty
int isEmpty() {
    return (front == -1 || front > rear);
}

// Insert an element into queue
void insert(char ch) {
    if (isFull()) {
        printf("Queue Overflow! Cannot insert '%c'.\n", ch);
        return;
    }
    if (front == -1)
        front = 0;
    queue[++rear] = ch;
    printf("Inserted '%c' into queue.\n", ch);
}

// Delete an element from queue
void delete() {
    if (isEmpty()) {
        printf("Queue Underflow! Cannot delete.\n");
        return;
    }
    printf("Deleted element: %c\n", queue[front++]);
}

// Display the queue
void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Current Queue (front to rear): ");
    for (int i = front; i <= rear; i++)
        printf("%c ", queue[i]);
    printf("\n");
}

int main() {
    int choice;
    char ch;

    while (1) {
        printf("\n--- QUEUE MENU ---\n");
        printf("1. Insert an Element into Queue\n");
        printf("2. Delete an Element from Queue\n");
        printf("3. Demonstrate Overflow / Underflow\n");
        printf("4. Display Queue\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter character to insert: ");
            scanf(" %c", &ch);
            insert(ch);
            break;

        case 2:
            delete();
            break;

        case 3:
            printf("\n--- Overflow Test ---\n");
            for (int i = 0; i < MAX + 1; i++)
                insert('A' + i);
            printf("\n--- Underflow Test ---\n");
            while (!isEmpty())
                delete();
            delete(); // One extra delete to show underflow
            break;

        case 4:
            display();
            break;

        case 5:
            printf("Exiting program...\n");
            return 0;

        default:
            printf("Invalid choice! Try again.\n");
        }
    }
}
