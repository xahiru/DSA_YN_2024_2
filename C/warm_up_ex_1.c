/*
Warm up exercise 1
1: Write a function to initialize an array of size 10 with the first 10 positive integers.
2: Given an array and an element, write a function to insert the element at a specified position.
3: Write a function to delete an element from an array at a specified position.
4: Write a function to search for the first occurrence of an element in an array and return its position.
5: Write a function that finds and returns the maximum element in an array.
*/

/*
Pseudo code:
1.
    Function InitializeArray():
        Create an array `arr` of size 10
        For i from 0 to 9:
            arr[i] = i + 1
        Return arr

2. 
    Function InsertElement(arr, element, position):
        If position < 0 or position > length of arr:
            Print "Invalid position"
            Return arr

        Create a new array `newArr` of size length of arr + 1
        For i from 0 to position - 1:
            newArr[i] = arr[i]
        
        newArr[position] = element

        For i from position to length of arr - 1:
            newArr[i + 1] = arr[i]

        Return newArr

3.

Function DeleteElement(arr, position):
    If position < 0 or position >= length of arr:
        Print "Invalid position"
        Return arr

    Create a new array `newArr` of size length of arr - 1
    For i from 0 to position - 1:
        newArr[i] = arr[i]

    For i from position + 1 to length of arr - 1:
        newArr[i - 1] = arr[i]

    Return newArr


4.
Function DeleteElement(arr, position):
    If position < 0 or position >= length of arr:
        Print "Invalid position"
        Return arr

    Create a new array `newArr` of size length of arr - 1
    For i from 0 to position - 1:
        newArr[i] = arr[i]

    For i from position + 1 to length of arr - 1:
        newArr[i - 1] = arr[i]

    Return newArr

5.
Function FindMaxElement(arr):
    If length of arr == 0:
        Print "Array is empty"
        Return None

    maxElement = arr[0]
    For i from 1 to length of arr - 1:
        If arr[i] > maxElement:
            maxElement = arr[i]
    Return maxElement


*/

// TODO: Implement the above pseudo code in C language
#include <stdio.h>

#define MAX_SIZE 100  // Define maximum size of the array

// Function to initialize an array with values 1 to 10
void InitializeArray(int arr[], int *size) {
    *size = 10;  // Initialize size to 10
    for (int i = 0; i < *size; i++) {
        arr[i] = i + 1;
    }
}

// Function to insert an element into the array at a given position
void InsertElement(int arr[], int *size, int element, int position) {
    if (position < 0 || position > *size || *size >= MAX_SIZE) {
        printf("Invalid position or array full\n");
        return;
    }

    // Shift elements to the right to make space for the new element
    for (int i = *size; i > position; i--) {
        arr[i] = arr[i - 1];
    }

    // Insert the new element at the desired position
    arr[position] = element;
    (*size)++;  // Increment size of the array
}

// Function to delete an element from the array at a given position
void DeleteElement(int arr[], int *size, int position) {
    if (position < 0 || position >= *size) {
        printf("Invalid position\n");
        return;
    }

    // Shift elements to the left to fill the gap left by the deleted element
    for (int i = position; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    (*size)--;  // Decrement size of the array
}

// Function to find the maximum element in the array
int FindMaxElement(int arr[], int size) {
    if (size == 0) {
        printf("Array is empty\n");
        return -1;
    }

    int maxElement = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > maxElement) {
            maxElement = arr[i];
        }
    }
    return maxElement;
}

// Function to display the elements of the array
void DisplayArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[MAX_SIZE];  // Array with a fixed size
    int size;

    // Initialize array
    InitializeArray(arr, &size);
    printf("Initial array: ");
    DisplayArray(arr, size);

    // Insert element
    InsertElement(arr, &size, 99, 5);
    printf("Array after insertion: ");
    DisplayArray(arr, size);

    // Delete element
    DeleteElement(arr, &size, 3);
    printf("Array after deletion: ");
    DisplayArray(arr, size);

    // Find max element
    int max = FindMaxElement(arr, size);
    printf("Maximum element in the array: %d\n", max);

    return 0;
}
