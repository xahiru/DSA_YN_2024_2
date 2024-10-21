#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

typedef struct {
    int *base; // Pointer to the array that holds queue elements
    int front; // Index of the front element
    int rear;  // Index of the rear element
} Deque;

// Initialize the deque
void initDeque(Deque *dq) {
    dq->base = (int *)malloc(MAXSIZE * sizeof(int));
    if (!dq->base) exit(1); // Memory allocation failed
    dq->front = 0;
    dq->rear = 0;
}

// Check if the deque is empty
int isEmptyDeque(Deque dq) {
    return dq.front == dq.rear;
}

// Insert an element at the rear of the deque
void insertRear(Deque *dq, int e) {
    if ((dq->rear + 1) % MAXSIZE == dq->front) {
        printf("Deque is full!\n");
        return;
    }
    dq->base[dq->rear] = e;
    dq->rear = (dq->rear + 1) % MAXSIZE;
}

// Remove an element from the front of the deque
int removeFront(Deque *dq) {
    if (isEmptyDeque(*dq)) {
        printf("Deque is empty!\n");
        exit(1);
    }
    int e = dq->base[dq->front];
    dq->front = (dq->front + 1) % MAXSIZE;
    return e;
}

// Insert an element at the front of the deque
void insertFront(Deque *dq, int e) {
    if ((dq->rear + 1) % MAXSIZE == dq->front) {
        printf("Deque is full!\n");
        return;
    }
    dq->front = (dq->front - 1 + MAXSIZE) % MAXSIZE;
    dq->base[dq->front] = e;
}

// Function to reverse the first k elements of the queue using a deque
void reverseFirstK(Deque *dq, int k) {
    // Use a temporary deque to store the first k elements in reverse order
    Deque tempDeque;
    initDeque(&tempDeque);

    // Remove the first k elements from the original deque and insert them into the tempDeque from the front
    for (int i = 0; i < k; ++i) {
        int e = removeFront(dq);
        insertFront(&tempDeque, e);
    }

    // Enqueue the elements back from the tempDeque to the original deque
    while (!isEmptyDeque(tempDeque)) {
        int e = removeFront(&tempDeque);
        insertRear(dq, e);
    }

    // Move the remaining elements to the back to maintain their order
    int s = (dq->rear - dq->front + MAXSIZE) % MAXSIZE - k;
    while (s-- > 0) {
        int x = removeFront(dq);
        insertRear(dq, x);
    }

    // Free the memory of the temporary deque
    free(tempDeque.base);
}

// Print the elements of the deque
void printDeque(Deque dq) {
    while (!isEmptyDeque(dq)) {
        printf("%d ", removeFront(&dq));
    }
    printf("\n");
}

// Driver code
int main() {
    Deque deque;
    initDeque(&deque);

    insertRear(&deque, 10);
    insertRear(&deque, 20);
    insertRear(&deque, 30);
    insertRear(&deque, 40);
    insertRear(&deque, 50);
    insertRear(&deque, 60);
    insertRear(&deque, 70);
    insertRear(&deque, 80);
    insertRear(&deque, 90);
    insertRear(&deque, 100);

    int k = 5;
    reverseFirstK(&deque, k);

    // Printing the deque
    printDeque(deque);

    // Free the allocated memory
    free(deque.base);

    return 0;
}
