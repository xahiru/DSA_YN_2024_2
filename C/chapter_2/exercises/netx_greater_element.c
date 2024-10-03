#include <stdio.h>
#include <stdlib.h>

void nextGreaterElement(int* arr, int size) {
    // Initialize a result array
    int* result = (int*)malloc(size * sizeof(int));
    
    // Fill the result array with -1
    for (int i = 0; i < size; i++) {
        result[i] = -1;
    }

    // Use a stack to keep track of indices
    int* stack = (int*)malloc(size * sizeof(int));
    int top = -1;

    for (int i = 0; i < size; i++) {
        // Check if the stack is not empty and the current element
        // is greater than the element at the index stored at the top of the stack
        while (top != -1 && arr[i] > arr[stack[top]]) {
            // Pop from the stack and assign the current element as the next greater
            result[stack[top]] = arr[i];
            top--;  // Pop the top of the stack
        }
        // Push the current index onto the stack
        stack[++top] = i;
    }

    // Print the result
    for (int i = 0; i < size; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    // Free the allocated memory
    free(result);
    free(stack);
}

int main() {
    int arr[] = {4, 7, 3, 4, 8, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    printf("Input array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nOutput array: ");
    
    nextGreaterElement(arr, size);

    return 0;
}
