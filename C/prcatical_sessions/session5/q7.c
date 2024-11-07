#include <stdio.h>
#define MAX_SIZE 100

// Define a structure for the queue
typedef struct {
    int items[MAX_SIZE]; // Array to store elements of the queue
    int front; // Index of the front element
    int rear; // Index of the rear element
} Queue;

// Function to create an empty queue
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue)); // Allocate memory for the queue
    q->front = -1; // Initialize front to -1
    q->rear = -1; // Initialize rear to -1
    return q; // Return the created queue
}

// Function to check if the queue is empty
int isEmpty(Queue* q) {
    return q->rear == -1; // Return 1 if rear is -1, indicating an empty queue
}

// Function to check if the queue is full
int isFull(Queue* q) {
    return q->rear == MAX_SIZE - 1; // Return 1 if rear is at the maximum size, indicating a full queue
}

// Function to add an element to the queue
void enqueue(Queue* q, int value) {
    if (isFull(q)) { // Check if the queue is full
        printf("Queue is full\n"); // Print error message if the queue is full
    } else {
        if (q->front == -1) { // Check if front is -1 (indicating an empty queue)
            q->front = 0; // Set front to 0
        }
        q->rear++; // Increment rear
        q->items[q->rear] = value; // Add the element to the rear of the queue
    }
}

// Function to remove an element from the queue
int dequeue(Queue* q) {
    int item;
    if (isEmpty(q)) { // Check if the queue is empty
        printf("Queue is empty\n"); // Print error message if the queue is empty
        item = -1; // Return -1 as an indication of an empty queue
    } else {
        item = q->items[q->front]; // Get the element at the front of the queue
        q->front++; // Increment front
        if (q->front > q->rear) { // Check if front has crossed rear (indicating an empty queue)
            q->front = q->rear = -1; // Reset front and rear to -1
        }
    }
    return item; // Return the removed element
}

// Function to reverse the elements in a queue
void reverse_queue(Queue* q) {
    int temp[MAX_SIZE]; // Temporary array to store elements
    int top = -1; // Initialize top of the temporary array

    // Dequeue elements from the queue and store them in the temporary array
    while (!isEmpty(q)) {
        temp[++top] = dequeue(q);
    }

    // Enqueue elements from the temporary array back to the queue, effectively reversing the order
    while (top != -1) {
        enqueue(q, temp[top--]);
    }
}

// Function to display the elements in the queue
void display(Queue* q) {
    if (isEmpty(q)) { // Check if the queue is empty
        printf("Queue is empty\n"); // Print message if the queue is empty
    } else {
        // Loop through the elements of the queue and print each element
        for (int i = q->front; i <= q->rear; i++) {
            printf("%d ", q->items[i]); // Print the element at index i
        }
        printf("\n"); // Print a newline after displaying all elements
    }
}

// Main function to test the program
int main() {
    Queue* q = createQueue(); // Create an empty queue

    // Add elements to the queue
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    enqueue(q, 5);

    // Display the elements in the queue
    printf("Queue elements are:\n");
    display(q);

    // Reverse the elements in the queue
    printf("Reverse Queue, elements are:\n");
    reverse_queue(q);

    // Display the elements in the reversed queue
    display(q);

    // Add two elements to the queue
    enqueue(q, 100);
    enqueue(q, 200);

    printf("Add two elements to the said queue:\n");    
    printf("Queue elements are:\n");
    display(q);

    // Reverse the elements in the queue
    printf("Reverse Queue, elements are:\n");
    reverse_queue(q);
    display(q);

    return 0; // Return from the main function
}
