
#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

struct Queue {
    int items[SIZE];
    int front;
    int rear;
};

struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

int isFull(struct Queue* q) {
    if (q->rear == SIZE - 1) {
        return 1;
    }
    return 0;
}

int isEmpty(struct Queue* q) {
    if (q->front == -1 || q->front > q->rear) {
        return 1;
    }
    return 0;
}

void enqueue(struct Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full!\n");
    } else {
        if (q->front == -1) {
            q->front = 0;  
        }
        q->rear++;
        q->items[q->rear] = value;
        printf("Inserted %d\n", value);
    }
}

int dequeue(struct Queue* q) {
    int item;
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    } else {
        item = q->items[q->front];
        q->front++;
        if (q->front > q->rear) {
            q->front = q->rear = -1;
        }
        printf("Removed %d\n", item);
        return item;
    }
}

void display(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue elements: ");
        for (int i = q->front; i <= q->rear; i++) {
            printf("%d ", q->items[i]);
        }
        printf("\n");
    }
}

int main() {
    struct Queue* q = createQueue();
    int choice, value;

    while (1) {
        printf("\nQueue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(q, value);
                break;
            case 2:
                dequeue(q);
                break;
            case 3:
                display(q);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}
