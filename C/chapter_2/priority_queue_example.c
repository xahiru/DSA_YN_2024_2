#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10

typedef struct {
    int data;
    int priority;
} Element;

typedef struct {
    Element items[MAXSIZE];
    int size;
} PriorityQueue;

// Initialize the priority queue
void initQueue(PriorityQueue *pq) {
    pq->size = 0;
}

// Check if the queue is full
int isFull(PriorityQueue *pq) {
    return pq->size == MAXSIZE;
}

// Check if the queue is empty
int isEmpty(PriorityQueue *pq) {
    return pq->size == 0;
}

// Enqueue an element based on its priority
void enqueue(PriorityQueue *pq, int value, int priority) {
    if (isFull(pq)) {
        printf("Queue is full!\n");
        return;
    }
    
    Element newElement;
    newElement.data = value;
    newElement.priority = priority;

    int i = pq->size - 1;
    
    // Shift elements that have lower priority
    while (i >= 0 && pq->items[i].priority > priority) {
        pq->items[i + 1] = pq->items[i];
        i--;
    }
    
    // Insert the new element at the correct position
    pq->items[i + 1] = newElement;
    pq->size++;
    
    printf("Enqueued: %d (Priority: %d)\n", value, priority);
}

// Dequeue the element with the highest priority (smallest priority number)
void dequeue(PriorityQueue *pq) {
    if (isEmpty(pq)) {
        printf("Queue is empty!\n");
    } else {
        printf("Dequeued: %d (Priority: %d)\n", pq->items[0].data, pq->items[0].priority);
        // Shift all elements forward
        for (int i = 1; i < pq->size; i++) {
            pq->items[i - 1] = pq->items[i];
        }
        pq->size--;
    }
}

// Display the elements of the priority queue
void display(PriorityQueue *pq) {
    if (isEmpty(pq)) {
        printf("Queue is empty!\n");
    } else {
        printf("Priority Queue elements:\n");
        for (int i = 0; i < pq->size; i++) {
            printf("%d (Priority: %d)\n", pq->items[i].data, pq->items[i].priority);
        }
    }
}

int main() {
    PriorityQueue pq;
    initQueue(&pq);

    enqueue(&pq, 10, 2);
    enqueue(&pq, 20, 1);
    enqueue(&pq, 30, 3);
    display(&pq);

    dequeue(&pq);
    display(&pq);

    enqueue(&pq, 40, 1);
    display(&pq);

    return 0;
}
