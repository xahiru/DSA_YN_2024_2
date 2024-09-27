#include <stdio.h>
#define MAXSIZE 5

typedef struct {
    int items[MAXSIZE];
    int front, rear;
} CircularQueue;

void initQueue(CircularQueue *q) {
    q->front = -1;
    q->rear = -1;
}

int isFull(CircularQueue *q) {
    return (q->rear + 1) % MAXSIZE == q->front;
}

int isEmpty(CircularQueue *q) {
    return q->front == -1;
}

void enqueue(CircularQueue *q, int value) {
    if (isFull(q)) {
        printf("Queue is full!\n");
    } else {
        if (q->front == -1) q->front = 0;
        q->rear = (q->rear + 1) % MAXSIZE;
        q->items[q->rear] = value;
        printf("Enqueued: %d\n", value);
    }
}

void dequeue(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
    } else {
        printf("Dequeued: %d\n", q->items[q->front]);
        if (q->front == q->rear) {
            q->front = q->rear = -1; // Queue becomes empty
        } else {
            q->front = (q->front + 1) % MAXSIZE;
        }
    }
}

void display(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue elements: ");
        int i = q->front;
        while (i != q->rear) {
            printf("%d ", q->items[i]);
            i = (i + 1) % MAXSIZE;
        }
        printf("%d\n", q->items[i]);
    }
}

int main() {
    CircularQueue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    display(&q);

    dequeue(&q);
    display(&q);

    enqueue(&q, 40);
    enqueue(&q, 50);
    enqueue(&q, 60); // Should display "Queue is full"
    display(&q);

    dequeue(&q);
    enqueue(&q, 70); // Should now be able to enqueue 70
    display(&q);

    return 0;
}
