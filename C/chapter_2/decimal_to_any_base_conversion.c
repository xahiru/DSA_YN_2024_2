#include <stdio.h>
#include <stdlib.h>

#define MAX 100  // Define maximum size for the stack

// Stack structure
typedef struct {
    int data[MAX];
    int top;
} Stack;

// Initialize the stack
void InitStack(Stack *S) {
    S->top = -1;
}

// Check if the stack is empty
int StackEmpty(Stack *S) {
    return S->top == -1;
}

// Push element onto the stack
void Push(Stack *S, int e) {
    if (S->top < MAX - 1) {
        S->data[++(S->top)] = e;
    } else {
        printf("Stack Overflow\n");
    }
}

// Pop element from the stack
void Pop(Stack *S, int *e) {
    if (!StackEmpty(S)) {
        *e = S->data[(S->top)--];
    } else {
        printf("Stack Underflow\n");
    }
}

// Conversion function that accepts any base
void conversion(int N, int base) {
    Stack S;
    InitStack(&S);
    
    while (N) {
        Push(&S, N % base);
        N = N / base;
    }
    
    while (!StackEmpty(&S)) {
        int e;
        Pop(&S, &e);
        // Handle bases greater than 10 by printing letters for values 10-15
        if (e >= 10) {
            printf("%c", 'A' + (e - 10));  // For hexadecimal conversion
        } else {
            printf("%d", e);
        }
    }
    printf("\n");
}

int main() {
    int N, base;
    
    printf("Enter a decimal number: ");
    scanf("%d", &N);
    
    printf("Enter the base to convert to (e.g., 8 for octal, 16 for hexadecimal): ");
    scanf("%d", &base);
    
    printf("The number %d in base %d is: ", N, base);
    conversion(N, base);
    
    return 0;
}
