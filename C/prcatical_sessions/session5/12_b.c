#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Queue structure definition
typedef struct {
    int data[MAX];
    int front, rear;
} Queue;

// Function to initialize the queue
void initializeQueue(Queue* q) {
    q->front = -1;
    q->rear = -1;
}

// Function to check if the queue is empty
int isEmpty(Queue* q) {
    return q->front == -1;
}

// Function to check if the queue is full
int isFull(Queue* q) {
    return q->rear == MAX - 1;
}

// Function to enqueue an element to the queue
void enqueue(Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full!\n");
        return;
    }
    if (q->front == -1) q->front = 0;  // If the queue is initially empty
    q->data[++(q->rear)] = value;
}

// Function to dequeue an element from the queue
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;  // Return -1 if the queue is empty
    }
    int value = q->data[q->front];
    if (q->front == q->rear) {  // If there's only one element
        q->front = q->rear = -1;
    } else {
        q->front++;
    }
    return value;
}

// Function to display the elements of the queue
void displayQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->data[i]);
    }
    printf("\n");
}

// Function to sort the elements of the queue in ascending order using enqueue and dequeue
void sortQueue(Queue* q) {
    Queue tempQueue;
    initializeQueue(&tempQueue);

    // Bubble sort using dequeue and enqueue
    int n = q->rear - q->front + 1;
    for (int i = 0; i < n - 1; i++) {
        int minValue = dequeue(q);
        for (int j = 1; j < n - i; j++) {
            int value = dequeue(q);
            if (value < minValue) {
                enqueue(&tempQueue, minValue);
                minValue = value;
            } else {
                enqueue(&tempQueue, value);
            }
        }
        enqueue(&tempQueue, minValue);
    }

    // Transfer the sorted elements back to the original queue
    while (!isEmpty(&tempQueue)) {
        enqueue(q, dequeue(&tempQueue));
    }
}

int main() {
    Queue q;
    initializeQueue(&q);

    // Input elements into the queue
    printf("Input some elements into the queue:\n");
    enqueue(&q, 4);
    enqueue(&q, 2);
    enqueue(&q, 7);
    enqueue(&q, 5);
    enqueue(&q, 1);

    printf("Elements of the queue:\n");
    displayQueue(&q);

    // Sort the queue
    sortQueue(&q);
    printf("Sort the said queue:\n");
    printf("Elements of the sorted queue in ascending order:\n");
    displayQueue(&q);

    // Input more elements into the queue
    printf("\nInput two more elements into the queue:\n");
    enqueue(&q, -1);
    enqueue(&q, 3);

    printf("Elements of the queue:\n");
    displayQueue(&q);

    // Sort the queue again
    sortQueue(&q);
    printf("Sort the said queue:\n");
    printf("Elements of the sorted queue in ascending order:\n");
    displayQueue(&q);

    return 0;
}
