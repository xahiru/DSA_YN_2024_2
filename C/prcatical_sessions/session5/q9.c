#include <stdio.h>

#define MAX_SIZE 100

int queue[MAX_SIZE]; // Array to store elements of the queue
int front = -1, back = -1; // Initialize front and back pointers

// Function to insert an element into the queue
void enqueue(int item) {
    if (back == MAX_SIZE - 1) { // Check if the queue is full
        printf("Error: Queue is full\n"); // Print error message if the queue is full
        return;
    }
    if (front == -1) { // Check if the queue is empty
        front = 0; // If empty, set front to 0
    }
    back++; // Increment the back pointer
    queue[back] = item; // Add the item to the queue
}

// Function to remove an element from a queue
int dequeue() {
    if (front == -1 || front > back) { // Check if the queue is empty
        printf("Error: Queue is empty\n"); // Print error message if the queue is empty
        return -1; // Return -1 to indicate an empty queue
    }
    int item = queue[front]; // Get the front element of the queue
    front++; // Move the front pointer to the next element
    return item; // Return the removed element
}

// Function to find the maximum value in the queue
int findMax() {
    if (front == -1 || front > back) { // Check if the queue is empty
        printf("Error: Queue is empty\n"); // Print error message if the queue is empty
        return -1; // Return -1 to indicate an empty queue
    }
    int max = queue[front]; // Initialize max with the first element of the queue
    // Loop through the elements of the queue to find the maximum value
    for (int i = front; i <= back; i++) {
        if (queue[i] > max) { // Compare the current element with max
            max = queue[i]; // Update max if the current element is greater
        }
    }
    return max; // Return the maximum value
}

// Function to display the elements in the queue
void display() {
    printf("Queue elements are: "); // Print message to indicate queue elements
    for (int i = front; i <= back; i++) { // Loop through the elements of the queue
        printf("%d ", queue[i]); // Print the current element
    }
    printf("\n"); // Print a newline after displaying all elements
}

int main() {
    // Insert some elements into the queue.
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    // Display the elements in the queue.
    display();
    // Find the maximum value in the queue.
    int max_val = findMax();
    printf("Maximum value in the queue is: %d\n", max_val);
    printf("\nRemove 2 elements from the said queue:\n");
    dequeue();
    dequeue();
    // Display the elements in the queue.
    display();
    // Recalculate the maximum value in the queue.
    max_val = findMax();
    printf("Maximum value in the queue is: %d\n", max_val);
    printf("\nInsert 3 more elements:\n");
    enqueue(600);
    enqueue(427);
    enqueue(519);
    // Display the elements in the queue.
    display();
    // Recalculate the maximum value in the queue.
    max_val = findMax();
    printf("Maximum value in the queue is: %d\n", max_val);
    return 0; // Return 0 to indicate successful execution
}
