// https://www.w3resource.com/c-programming-exercises/stack/c-stack-exercise-1.phps
#include <stdio.h>

#define MAX_SIZE 100 // Maximum size of the stack

int stack[MAX_SIZE]; // Array to implement the stack
int top = -1; // Variable to keep track of the top of the stack, initialized as -1 indicating an empty stack

// Function to push an element onto the stack
void push(int data) {
    if (top == MAX_SIZE - 1) { // Check for stack overflow
        printf("Overflow stack!\n");
        return;
    }
    top++; // Move the top pointer to the next position
    stack[top] = data; // Add the data to the stack at the current top position
}

// Function to pop an element from the stack
int pop() {
    if (top == -1) { // Check if the stack is empty
        printf("Stack is empty!\n");
        return -1;
    }
    int data = stack[top]; // Get the data at the top of the stack
    top--; // Move the top pointer down to the previous position
    return data; // Return the popped data
}

int main() {
    // Pushing elements onto the stack
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    push(3); // Attempting to push another element when the stack is full

    printf("Elements in the stack are: ");
    // Popping and printing elements until the stack is empty
    while (top != -1) {
        printf("%d ", pop()); // Display the popped element
    }
    printf("\n");
    return 0;
}
