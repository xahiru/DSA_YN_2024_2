#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Define the stack structure
struct Stack {
    char arr[MAX];
    int top;
};

// Initialize the stack
void initializeStack(struct Stack* stack) {
    stack->top = -1;
}

// Push an element onto the stack
void push(struct Stack* stack, char ch) {
    if (stack->top == MAX - 1) {
        printf("Stack overflow!\n");
        return;
    }
    stack->arr[++stack->top] = ch;
}

// Pop an element from the stack
char pop(struct Stack* stack) {
    if (stack->top == -1) {
        return '\0';
    }
    return stack->arr[stack->top--];
}

// Check if the parentheses are balanced
int isBalanced(char* str) {
    struct Stack stack;
    initializeStack(&stack);

    for (int i = 0; str[i] != '\0'; i++) {
        char ch = str[i];
        if (ch == '(' || ch == '{' || ch == '[') {
            push(&stack, ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            char top = pop(&stack);
            if ((ch == ')' && top != '(') || (ch == '}' && top != '{') || (ch == ']' && top != '[')) {
                return 0;  // Not balanced
            }
        }
    }

    return stack.top == -1;  // If the stack is empty, it's balanced
}

int main() {
    char expression[] = "{[()]}";
    if (isBalanced(expression)) {
        printf("Balanced\n");
    } else {
        printf("Not Balanced\n");
    }
    return 0;
}
