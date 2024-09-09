#include <stdio.h>
#include <stdlib.h>

// Define a node
struct Node {
    int data;
    struct Node* next;
};

// Define the queue with front and rear pointers
struct Queue {
    struct Node *front, *rear;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// Function to create a new queue
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

// Function to add an element to the queue
void enqueue(struct Queue* q, int data) {
    struct Node* temp = newNode(data);
    
    // If the queue is empty, new node is front and rear both
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    
    // Add the new node at the end of the queue and change rear
    q->rear->next = temp;
    q->rear = temp;
}

// Function to remove an element from the queue
void dequeue(struct Queue* q) {
    // If queue is empty, return NULL
    if (q->front == NULL)
        return;

    // Store previous front and move front one node ahead
    struct Node* temp = q->front;
    q->front = q->front->next;

    // If front becomes NULL, then change rear also to NULL
    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
}

// Function to display the queue elements
void display(struct Queue* q) {
    struct Node* temp = q->front;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Queue* q = createQueue();
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    printf("Queue elements: ");
    display(q);
    
    dequeue(q);
    printf("After dequeue, queue elements: ");
    display(q);
    
    return 0;
}
