#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Global stack and top variables
int stack[MAX_SIZE];
int top = -1;

// Function to push an element onto the stack
void push(int data) {
    if (top == MAX_SIZE - 1) {
        printf("Overflow stack!\n");
        return;
    }
    top++;
    stack[top] = data;
}

// Function to pop an element from the stack
int pop() {
    if (top == -1) {
        printf("Empty stack!\n");
        return -1;
    }
    int data = stack[top];
    top--;
    return data;
}

// Function to print the next greater elements
void print_next_greater_element(int arr[], int n) {
    int i, next, element;
    // Push the first element onto the stack
    push(arr[0]);

    // Iterate through the array
    for (i = 1; i < n; i++) {
        next = arr[i];
        if (top != -1) {
            element = pop();
            // Find the next greater element
            while (element < next) {
                printf("%d --> %d\n", element, next);
                if (top == -1) {
                    break;
                }
                element = pop();
            }
            if (element > next) {
                push(element);
            }
        }
        // Push the current element onto the stack
        push(next);
    }
    // Remaining elements in the stack have no greater element
    while (top != -1) {
        element = pop();
        next = -1;
        printf("%d --> %d\n", element, next);
    }
}

int main() {
    int n = 6;
    int i = 0;
    int arr[6] = {1, 2, 3, 4, 5, 6};
    printf("Elements in the array are: ");
    for (i = 0; i < 6; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nThe next larger elements are: \n");
    print_next_greater_element(arr, n);

    // More arrays to test
    // ...

    return 0;
}
