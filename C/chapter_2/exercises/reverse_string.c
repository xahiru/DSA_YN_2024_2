#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    return *(--s->top);
}

// Function to reverse a string using a stack
void ReverseString(char *str) {
    int len = strlen(str);
    CharStack stack;
    InitStack(&stack, len);

    // Push all characters of the string onto the stack
    for (int i = 0; i < len; i++) {
        Push(&stack, str[i]);
    }

    // Pop characters from the stack and place them back into the string
    for (int i = 0; i < len; i++) {
        str[i] = Pop(&stack);
    }

    free(stack.base);  // Free the allocated memory for the stack
}

int main() {
    char str[] = "hello";
    printf("Original string: %s\n", str);
    
    ReverseString(str);
    
    printf("Reversed string: %s\n", str);
    
    return 0;
}
