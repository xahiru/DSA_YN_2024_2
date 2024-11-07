 #include <stdio.h>
#include <stdlib.h>

// Define the node structure for the linked list
typedef struct node {
    int data;
    int sum;
    struct node* next;
} Node;

// Define the stack structure
typedef struct stack {
    Node* top;
    int size;
} Stack;

// Function to initialize the stack
void init(Stack* s) {
    s->top = NULL; // Set top pointer to NULL indicating an empty stack
    s->size = 0; // Initialize the size of the stack to 0
}

// Function to push an element onto the stack
void push(Stack* s, int value) {
    Node* new_node = (Node*) malloc(sizeof(Node)); // Create a new node
    new_node->data = value; // Set the data of the new node to the given value
    // Calculate the sum of the stack elements up to this node
    new_node->sum = (s->top == NULL) ? value : s->top->sum + value;
    new_node->next = s->top; // Set the new node's next pointer to the top node
    s->top = new_node; // Update the top pointer to the new node
    s->size++; // Increment the size of the stack
}

// Function to pop an element from the stack
int pop(Stack* s) {
    if (s->top == NULL) { // Check if the stack is empty
        printf("Error: Stack underflow\n");
        exit(1);
    }
    int value = s->top->data; // Get the data of the top node
    Node* temp = s->top; // Create a temporary pointer to the top node
    s->top = s->top->next; // Move the top pointer to the next node
    s->size--; // Decrement the size of the stack
    free(temp); // Free the memory of the popped node
    return value; // Return the popped value
}

// Function to get the average of the elements in the stack
float get_average(Stack* s) {
    if (s->size == 0) { // Check if the stack is empty
        printf("Error: Stack is empty\n");
        exit(1);
    }
    return (float) s->top->sum / s->size; // Calculate and return the average
}

// Function to print the elements of the stack
void printStack(Stack* s) {
    if (s->size == 0) { // Check if the stack is empty
        printf("Stack is empty\n");
        return;
    }

    struct node* current = s->top;
    while (current != NULL) { // Iterate through the stack and print each element
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Main function
int main() {
    float avg_val;
    Stack s;
    // Call the function init() to initialize the stack
    init(&s);

    // Push some elements onto the stack
    push(&s, 1);
    push(&s, 3);
    push(&s, 5);
    push(&s, 2);
    push(&s, 4);
    push(&s, 6);
    printf("Elements of the stack:\n");
    printStack(&s);
    // Get the average of the elements in the stack
    avg_val = get_average(&s);
    printf("Average of the said stack values: %0.2f\n", avg_val);
    // Pop an element from the stack
    int popped_value = pop(&s);
    printf("\nPopped value: %d\n", popped_value);
    printf("\nElements of the stack:\n");
    printStack(&s);
    // Get the average of the elements in the stack
    avg_val = get_average(&s);
    printf("Average of the said stack values: %0.2f\n", avg_val);
    return 0;
}
