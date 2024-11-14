
#include <stdio.h>
#include <string.h>

#define MAX 10  // Max actions in the stack

// Define the stack structure for undo operations
struct Stack {
    char actions[MAX][100];
    int top;
};

// Initialize the stack
void initializeStack(struct Stack* stack) {
    stack->top = -1;
}

// Perform an action and push it to the stack
void performAction(struct Stack* stack, const char* action) {
    if (stack->top < MAX - 1) {
        stack->top++;
        strcpy(stack->actions[stack->top], action);
        printf("Performed: %s\n", action);
    } else {
        printf("Stack overflow. Cannot perform more actions.\n");
    }
}

// Undo the last action
void undoAction(struct Stack* stack) {
    if (stack->top == -1) {
        printf("No actions to undo.\n");
    } else {
        printf("Undoing: %s\n", stack->actions[stack->top]);
        stack->top--;
    }
}

int main() {
    struct Stack actionStack;
    initializeStack(&actionStack);

    performAction(&actionStack, "Type text: Hello World");
    performAction(&actionStack, "Bold text");
    performAction(&actionStack, "Change font size");

    undoAction(&actionStack);
    undoAction(&actionStack);
    undoAction(&actionStack);
    undoAction(&actionStack);  // Empty stack case

    return 0;
}
