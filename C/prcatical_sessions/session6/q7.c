#include <stdio.h>
#include <stdlib.h>

#define MAX 50  // Define maximum stack size

// Stack structure definition
struct Stack {
    int arr[MAX];
    int top;
};

// Initialize the stack
void initializeStack(struct Stack* stack) {
    stack->top = -1;
}

// Push an element onto the stack
void push(struct Stack* stack, int value) {
    if (stack->top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack->arr[++stack->top] = value;
}

// Pop an element from the stack
int pop(struct Stack* stack) {
    if (stack->top == -1) {
        printf("Stack Underflow\n");
        return -1;  // Return a sentinel value for error
    }
    return stack->arr[stack->top--];
}

// Function to convert a decimal number to base 3
void convertToBase3(int number) {
    if (number == 0) {
        printf("0");
        return;
    }

    struct Stack stack;
    initializeStack(&stack);

    while (number > 0) {
        push(&stack, number % 3);  // Push the remainder (base 3 digit)
        number = number / 3;       // Divide the number by 3
    }

    // Pop from stack to get the base 3 digits in correct order
    while (stack.top != -1) {
        printf("%d", pop(&stack));
    }
}

int main() {
    int number;

    // Input from the user
    printf("Enter a number in base 10: ");
    scanf("%d", &number);

    printf("The number in base 3 is: ");
    convertToBase3(number);
    printf("\n");

    return 0;
}
