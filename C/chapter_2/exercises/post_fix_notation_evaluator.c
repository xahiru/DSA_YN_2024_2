#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100  // Maximum size of the stack

// Define a stack structure for integers
typedef struct {
    int data[MAX];
    int top;
} Stack;

// Function to initialize the stack
void InitStack(Stack *s) {
    s->top = -1;
}

// Function to check if the stack is empty
int isEmpty(Stack *s) {
    return s->top == -1;
}

// Function to push an element onto the stack
void Push(Stack *s, int value) {
    if (s->top == MAX - 1) {
        printf("Stack overflow\n");
        return;
    }
    s->data[++(s->top)] = value;
}

// Function to pop an element from the stack
int Pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack underflow\n");
        exit(1);
    }
    return s->data[(s->top)--];
}

// Function to evaluate a postfix expression
int EvaluatePostfix(char *expression) {
    Stack stack;
    InitStack(&stack);

    char *token = strtok(expression, " ");  // Tokenize the input string by spaces
    while (token != NULL) {
        // If the token is a number, push it onto the stack
        if (isdigit(token[0])) {
            Push(&stack, atoi(token));
        }
        // If the token is an operator, pop two elements from the stack, apply the operator, and push the result
        else {
            int operand2 = Pop(&stack);  // Second operand is popped first
            int operand1 = Pop(&stack);  // First operand is popped second

            int result;
            switch (token[0]) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
                default:
                    printf("Invalid operator: %c\n", token[0]);
                    exit(1);
            }

            // Push the result back onto the stack
            Push(&stack, result);
        }

        token = strtok(NULL, " ");  // Get the next token
    }

    // At the end, the result is the only element left in the stack
    return Pop(&stack);
}

int main() {
    char expression[] = "5 1 2 + 4 * + 3 -";
    printf("Postfix Expression: %s\n", expression);

    int result = EvaluatePostfix(expression);
    printf("Result: %d\n", result);  // Output should be 14

    return 0;
}
