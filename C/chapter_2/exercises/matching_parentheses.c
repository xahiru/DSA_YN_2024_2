#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define a simple stack structure for characters
typedef struct {
    char *base;
    char *top;
    int stacksize;
} CharStack;

// Function to initialize the stack
void InitStack(CharStack *s, int size) {
    s->base = (char *)malloc(size * sizeof(char));
    if (!s->base) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    s->top = s->base;
    s->stacksize = size;
}

// Function to push a character onto the stack
void Push(CharStack *s, char e) {
    *s->top++ = e;
}

// Function to pop a character from the stack
char Pop(CharStack *s) {
    if (s->top == s->base) {  // If stack is empty
        return '\0';
    }
    return *(--s->top);
}

// Function to check if two parentheses are matching pairs
bool isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') || 
           (open == '{' && close == '}') || 
           (open == '[' && close == ']');
}

// Function to check if a string of parentheses is balanced
bool isBalanced(char *str) {
    CharStack stack;
    InitStack(&stack, 100);  // Assume max length of string is 100, adjust if needed

    for (int i = 0; str[i] != '\0'; i++) {
        char ch = str[i];

        // Push opening parentheses onto the stack
        if (ch == '(' || ch == '{' || ch == '[') {
            Push(&stack, ch);
        }
        // If closing parenthesis, check for matching opening parenthesis
        else if (ch == ')' || ch == '}' || ch == ']') {
            char open = Pop(&stack);
            if (!isMatchingPair(open, ch)) {
                return false;  // Mismatched parentheses
            }
        }
    }

    // If stack is empty, parentheses are balanced
    bool balanced = (stack.top == stack.base);
    free(stack.base);  // Free the allocated memory for the stack
    return balanced;
}

int main() {
    char str1[] = "{[()]}";  // Balanced
    char str2[] = "{[(])}";  // Not balanced

    if (isBalanced(str1)) {
        printf("String '%s' is balanced.\n", str1);
    } else {
        printf("String '%s' is not balanced.\n", str1);
    }

    if (isBalanced(str2)) {
        printf("String '%s' is balanced.\n", str2);
    } else {
        printf("String '%s' is not balanced.\n", str2);
    }

    return 0;
}
