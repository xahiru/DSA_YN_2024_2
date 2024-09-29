#include <stdio.h>
#include <stdlib.h>

#define STACK_INIT_SIZE   100
#define STACK_INCREMENT   10

typedef int SElemType;
typedef int Status;

#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef struct {
    SElemType *base;
    SElemType *top;
    int stacksize;
} SqStack;

// Function to initialize the stack
Status InitStack(SqStack *s) {
    s->base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
    if (!s->base) exit(OVERFLOW);
    s->top = s->base;  // Stack is initially empty
    s->stacksize = STACK_INIT_SIZE;
    return OK;
}

// Function to push an element onto the stack
Status Push(SqStack *s, SElemType e) {
    if (s->top - s->base >= s->stacksize) {  // If the stack is full
        s->base = (SElemType *)realloc(s->base, (s->stacksize + STACK_INCREMENT) * sizeof(SElemType));
        if (!s->base) exit(OVERFLOW);
        s->top = s->base + s->stacksize;  // Adjust the top pointer after reallocation
        s->stacksize += STACK_INCREMENT;
    }
    *s->top++ = e;  // Push the element
    return OK;
}

// Function to pop an element from the stack
Status Pop(SqStack *s, SElemType *e) {
    if (s->top == s->base) return ERROR;  // Stack underflow
    *e = *--s->top;  // Pop the element
    return OK;
}

// Function to peek at the top element of the stack
SElemType Peek(SqStack *s) {
    if (s->top == s->base) {
        printf("Stack is empty\n");
        exit(ERROR);
    }
    return *(s->top - 1);  // Return the top element
}

// Function to display the stack elements
void Display(SqStack *s) {
    if (s->top == s->base) {
        printf("Stack is empty\n");
        return;
    }
    SElemType *p = s->base;
    while (p != s->top) {
        printf("%d ", *p);  // Print each element in the stack
        p++;
    }
    printf("\n");
}

// Main function with switch menu
int main() {
    SqStack stack;
    InitStack(&stack);

    int choice;
    int x;
    SElemType e;

    while (1) {
        printf("\nPerform operations on the stack:");
        printf("\n1. Push an element\n2. Pop an element\n3. Display stack\n4. Peek top element\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter the element to be pushed onto the stack: ");
                scanf("%d", &x);
                Push(&stack, x);
                break;
            case 2:
                if (Pop(&stack, &e) == OK) {
                    printf("Popped: %d\n", e);
                } else {
                    printf("Stack is empty, cannot pop.\n");
                }
                break;
            case 3:
                printf("Stack elements: ");
                Display(&stack);
                break;
            case 4:
                printf("Top element is: %d\n", Peek(&stack));
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!!\n");
        }
    }

    return 0;
}
