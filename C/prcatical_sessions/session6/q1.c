#include <stdio.h>
#include <stdlib.h>

// Define a node structure for the linked list
struct Node {
    int data;
    struct Node* next;
};

// Define a queue structure
struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Function to initialize the queue
void initializeQueue(struct Queue* q) {
    q->front = q->rear = NULL;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* q) {
    return q->front == NULL;
}

// Function to add an element to the queue (enqueue)
void enqueue(struct Queue* q, int value) {
    // Create a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;
    
    // If the queue is empty, both front and rear will point to the new node
    if (isEmpty(q)) {
        q->front = q->rear = newNode;
    } else {
        // Add the new node to the end of the queue and update rear
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

// Function to remove an element from the queue (dequeue)
int dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty! Cannot dequeue.\n");
        return -1;  // Return an error code for empty queue
    }
    
    // Remove the front node
    struct Node* temp = q->front;
    int value = temp->data;
    
    q->front = q->front->next;
    
    // If the queue becomes empty, set rear to NULL
    if (q->front == NULL) {
        q->rear = NULL;
    }
    
    free(temp);
    return value;
}

// Function to get the front element without removing it (peek)
int peek(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty! Cannot peek.\n");
        return -1;  // Return an error code for empty queue
    }
    
    return q->front->data;
}

// Function to display the contents of the queue
void display(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }

    struct Node* temp = q->front;
    printf("Queue: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function to test the queue operations
int main() {
    struct Queue q;
    initializeQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);

    display(&q);

    printf("Dequeued: %d\n", dequeue(&q));
    display(&q);

    printf("Front element: %d\n", peek(&q));

    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    display(&q);  // Should print "Queue is empty!"

    return 0;
}
