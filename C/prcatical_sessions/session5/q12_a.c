#include <stdio.h>

#define MAX_SIZE 100 // Define the maximum size of the queue

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

// Function to remove an element from the queue
int dequeue() {
    if (front == -1 || front > back) { // Check if the queue is empty
        printf("Error: Queue is empty\n"); // Print error message if the queue is empty
        return -1; // Return -1 to indicate an empty queue
    }
    int item = queue[front]; // Get the front element of the queue
    front++; // Move the front pointer to the next element
    return item; // Return the removed element
}

// Function to display the elements in the queue
void display() {
    if (front == -1) { // Check if the queue is empty
        printf("Error: Queue is empty\n"); // Print error message if the queue is empty
        return;
    }
    for (int i = front; i <= back; i++) { // Loop through the elements of the queue
        printf("%d ", queue[i]); // Print the current element
    }
    printf("\n"); // Print a newline after displaying all elements
}

// Function to sort the queue in ascending order
void sort_queue_asc() {
    int i, j, temp;
    int n = back - front + 1; // Calculate the number of elements in the queue

    for (i = 0; i < n - 1; i++) { // Iterate through the queue elements
        for (j = i + 1; j < n; j++) { // Iterate through the remaining elements
            if (queue[i] > queue[j]) { // Compare adjacent elements
                temp = queue[i]; // Swap elements if out of order
                queue[i] = queue[j];
                queue[j] = temp;
            }
        }
    }
}

int main() {
    // Insert elements into the queue
    printf("Input some elements into the queue:");
    enqueue(4);
    enqueue(2);
    enqueue(7);
    enqueue(5);
    enqueue(1);
    // Display the unsorted queue
    printf("\nElements of the queue:\n");
    display();
    // Sort the queue
    printf("\nSort the said queue:");
    sort_queue_asc();
    // Display the sorted queue
    printf("\nElements of the sorted queue in ascending order:\n");
    display();
    printf("\nInput two more elements into the queue:");
    enqueue(-1);
    enqueue(3);
    printf("\nElements of the queue:\n");
    display();
    printf("\nSort the said queue:");
    sort_queue_asc();
    // Display the sorted queue
    printf("\nElements of the sorted queue in ascending order:\n");
    display();
    return 0;
}
