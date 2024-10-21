#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

typedef struct {
    int *base; // Pointer to the array that holds queue elements
    int front; // Index of the front element
    int rear;  // Index of the rear element
} SqQueue;

// Initialize the queue
void initQueue(SqQueue *q) {
    q->base = (int *)malloc(MAXSIZE * sizeof(int));
    if (!q->base) exit(1); // Memory allocation failed
    q->front = 0;
    q->rear = 0;
}

// Check if the queue is empty
int isEmpty(SqQueue q) {
    return q.front == q.rear;
}

// Enqueue an element to the queue
void enqueue(SqQueue *q, int e) {
    if ((q->rear + 1) % MAXSIZE == q->front) {
        printf("Queue is full!\n");
        return;
    }
    q->base[q->rear] = e;
    q->rear = (q->rear + 1) % MAXSIZE;
}

// Dequeue an element from the queue
int dequeue(SqQueue *q) {
    if (isEmpty(*q)) {
        printf("Queue is empty!\n");
        exit(1);
    }
    int e = q->base[q->front];
    q->front = (q->front + 1) % MAXSIZE;
    return e;
}

// Function to reverse the first k elements of the queue
void solve(SqQueue *q, int k) {
    if (k == 0) return;
    int e = dequeue(q);
    solve(q, k - 1);
    enqueue(q, e);
}

void reverseFirstK(SqQueue *q, int k) {
    solve(q, k);
    int s = (q->rear - q->front + MAXSIZE) % MAXSIZE - k;
    while (s-- > 0) {
        int x = dequeue(q);
        enqueue(q, x);
    }
}

// Print the elements of the queue
void printQueue(SqQueue q) {
    while (!isEmpty(q)) {
        printf("%d ", dequeue(&q));
    }
    printf("\n");
}

// Driver code
int main() {
    SqQueue queue;
    initQueue(&queue);

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);
    enqueue(&queue, 40);
    enqueue(&queue, 50);
    enqueue(&queue, 60);
    enqueue(&queue, 70);
    enqueue(&queue, 80);
    enqueue(&queue, 90);
    enqueue(&queue, 100);

    int k = 5;
    reverseFirstK(&queue, k);

    // Printing queue
    printQueue(queue);

    // Free the allocated memory
    free(queue.base);

    return 0;
}
