#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_SIZE 100

// Arrays to maintain the main stack and the stack for tracking minimum elements
int mainStack[MAX_SIZE];
int minStack[MAX_SIZE];
int top = -1; // Top index of the main stack
int min_Top = -1; // Top index of the minimum stack

// Function to push an element onto the main stack
void push(int element) {
    if (top >= MAX_SIZE - 1) {
        printf("Stack is full\n");
        return;
    }

    // Push the element onto the main stack
    top++;
    mainStack[top] = element;

    // If the minStack is empty or the element is less than or equal to the top element in minStack,
    // push the element onto the minStack to track minimum elements
    if (min_Top == -1 || element <= minStack[min_Top]) {
        min_Top++;
        minStack[min_Top] = element;
    }
}

// Function to pop an element from the main stack
int pop() {
    if (top < 0) {
        printf("Stack is empty\n");
        return INT_MIN;
    }

    // Pop the top element from the main stack
    int element = mainStack[top];
    top--;

    // If the popped element is the top element in minStack, also pop it from minStack
    if (element == minStack[min_Top]) {
        min_Top--;
    }

    return element;
}

// Function to get the minimum element from the main stack
int getMin() {
    if (min_Top < 0) {
        printf("Stack is empty\n");
        return INT_MIN;
    }

    return minStack[min_Top];
}

// Function to print the elements of the stack
void printstack(int *stack) {
    printf("Current stack elements:\n");
    for (int i = 0; i <= top; i++) {
        printf("%d ", stack[i]);
    }
}

int main() {
    // Example usage of the stack functions
    push(9);
    push(2);
    push(4);
    push(2);
    push(4);
    printstack(mainStack);
    printf("\nMinimum element: %d\n", getMin()); 
    pop();
    pop();
    printf("\nAfter removing two elements:\n");
    printstack(mainStack);
    printf("\nMinimum element: %d\n", getMin());  
    push(1);
    printf("\nAfter adding one element:\n");
    printstack(mainStack);
    printf("\nMinimum element: %d\n", getMin());      
    return 0;
}
