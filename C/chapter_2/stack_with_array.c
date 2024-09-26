#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // Define maximum size of the stack

// Define the structure for a stack
struct Stack {
    int arr[MAX];  // Array to store stack elements
    int top;       // Index of the top element in the stack
};

// Function to initialize the stack
void initStack(struct Stack* stack) {
    stack->top = -1;  // Initialize top to -1 indicating the stack is empty
}

// Function to check if the stack is full
int isFull(struct Stack* stack) {
    return stack->top == MAX - 1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to push an element onto the stack
void push(struct Stack* stack, int data) {
    if (isFull(stack)) {
        printf("Stack overflow! Unable to push %d\n", data);
        return;
    }
    stack->arr[++stack->top] = data;
    printf("Pushed %d onto the stack.\n", data);
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow! No elements to pop.\n");
        return -1;
    }
    int poppedValue = stack->arr[stack->top--];
    return poppedValue;
}

// Function to get the top element of the stack (without popping it)
int peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty! Nothing to peek.\n");
        return -1;
    }
    return stack->arr[stack->top];
}

// Function to display the elements in the stack
void display(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = stack->top; i >= 0; i--) {
        printf("%d ", stack->arr[i]);
    }
    printf("\n");
}

int main() {
    struct Stack stack;
    initStack(&stack);  // Initialize the stack

    // Push elements onto the stack
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    push(&stack, 40);
    push(&stack, 50);

    display(&stack);  // Display the stack

    // Try pushing when the stack is full
    push(&stack, 60);

    // Pop elements from the stack
    printf("Popped: %d\n", pop(&stack));
    printf("Popped: %d\n", pop(&stack));

    display(&stack);  // Display the stack after popping

    // Peek at the top element
    printf("Top element is: %d\n", peek(&stack));

    return 0;
}
