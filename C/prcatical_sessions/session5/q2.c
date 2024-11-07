#include <stdio.h>
#define MAX_SIZE 100 // Define the maximum size of the queue

int queue[MAX_SIZE]; // Declare an array to store queue elements
int front = -1; // Initialize front of the queue
int back = -1; // Initialize back of the queue

// Function to insert an element into the queue
void enqueue(int item) {
    if (back == MAX_SIZE - 1) { // Check if the queue is full
        printf("Error: Queue is full\n"); // Print error message if queue is full
        return; // Return from the function
    }
    if (front == -1) { // Check if the queue is empty
        front = 0; // Set front to 0 if queue is empty
    }
    back++; // Increment back to insert the new element
    queue[back] = item; // Insert the item into the queue
}

// Function to remove an element from the queue
void dequeue() {
    if (front == -1 || front > back) { // Check if the queue is empty
        printf("Error: Queue is empty\n"); // Print error message if queue is empty
        return; // Return from the function
    }
    front++; // Increment front to remove the element
}

// Function to display the elements in the queue
void display() {
    if (front == -1 || front > back) { // Check if the queue is empty
        printf("Queue is empty\n"); // Print message if queue is empty
        return; // Return from the function
    }
    printf("Queue elements are: "); // Print message to display queue elements
    for (int i = front; i <= back; i++) { // Iterate over the queue elements
        printf("%d ", queue[i]); // Print each element of the queue
    }
    printf("\n"); // Print newline after displaying all elements
}

int main() {
    printf("Initialize a queue!"); // Print message to indicate initializing a queue
    // Insert some elements into the queue.
    printf("\nInsert some elements into the queue:\n"); // Print message to indicate inserting elements into the queue
    enqueue(1); // Insert element 1 into the queue
    enqueue(2); // Insert element 2 into the queue
    enqueue(3); // Insert element 3 into the queue
    display(); // Display the elements of the queue
    printf("\nDelete an element from the queue:\n"); // Print message to indicate deleting an element from the queue
    dequeue(); // Remove an element from the queue
    display(); // Display the elements of the queue after deletion
    printf("\nInsert another element into the queue:\n"); // Print message to indicate inserting another element
    enqueue(4); // Insert element 4 into the queue
    display(); // Display the elements of the queue
    return 0; // Return from the main function
}
