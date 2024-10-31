#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Global stack and top variable declaration
char stack[MAX_SIZE];
int top = -1;

// Function to push a character onto the stack
void push(char data) {
    if (top == MAX_SIZE - 1) {
        printf("Overflow stack!\n");
        return;
    }
    top++;
    stack[top] = data;
}

// Function to pop a character from the stack
char pop() {
    if (top == -1) {
        printf("Empty Stack!\n");
        return '\0';
    }
    char data = stack[top];
    top--;
    return data;
}

// Function to reverse a string using a stack
void reverse_string(char *str) {
    int len = strlen(str);

    // Push each character of the string onto the stack
    for (int i = 0; i < len; i++) {
        push(str[i]);
    }

    // Pop characters from the stack to reverse the string
    for (int i = 0; i < len; i++) {
        str[i] = pop();
    }
}

// Main function
int main() {
    char text[MAX_SIZE];
    printf("Input a string: ");
    fgets(text, MAX_SIZE, stdin);

    // Remove newline character from input
    text[strcspn(text, "\n")] = '\0';

    // Reverse the input string using the stack
    reverse_string(text);

    // Print the reversed string
    printf("Reversed string using a stack is: %s\n", text);

    return 0;
}
