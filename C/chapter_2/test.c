#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

// Stack for operators
char stack[MAX];
int top = -1;

// Function to push an operator to the stack
void push(char op) {
    if (top >= MAX - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = op;
}

// Function to pop an operator from the stack
char pop() {
    if (top < 0) {
        printf("Stack underflow\n");
        return '\0';
    }
    return stack[top--];
}

// Function to peek the top of the stack
char peek() {
    if (top < 0) {
        return '\0';
    }
    return stack[top];
}

// Function to check if a character is an operator
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

// Function to determine precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    }
    if (op == '*' || op == '/') {
        return 2;
    }
    return 0;
}

// Recursive Descent Parsing Functions

// Forward declaration of expr() to resolve circular dependency
void expr();

// Function to handle factors (either numbers or parenthesis)
void factor() {
    char ch;
    scanf(" %c", &ch);

    if (isdigit(ch)) {
        // If it's a digit, directly print it (as it's RPN output)
        printf("%c ", ch);
    } else if (ch == '(') {
        // If it's '(', we parse the expression inside the parentheses
        expr();
        // Read the closing ')'
        scanf(" %c", &ch);
    }
}

// Function to handle terms (i.e., multiplication or division)
void term() {
    // Parse the first factor
    factor();
    
    // Check for more '*' or '/' operators
    char ch;
    while (1) {
        scanf(" %c", &ch);
        if (ch == '*' || ch == '/') {
            // Push operator to the stack
            while (top >= 0 && precedence(peek()) >= precedence(ch)) {
                printf("%c ", pop());
            }
            push(ch);
            // Parse the next factor
            factor();
        } else {
            // If not an operator, put it back into the input stream
            ungetc(ch, stdin);
            break;
        }
    }
}

// Function to handle expressions (i.e., addition or subtraction)
void expr() {
    // Parse the first term
    term();
    
    // Check for more '+' or '-' operators
    char ch;
    while (1) {
        scanf(" %c", &ch);
        if (ch == '+' || ch == '-') {
            // Push operator to the stack
            while (top >= 0 && precedence(peek()) >= precedence(ch)) {
                printf("%c ", pop());
            }
            push(ch);
            // Parse the next term
            term();
        } else {
            // If not an operator, put it back into the input stream
            ungetc(ch, stdin);
            break;
        }
    }
}

// Function to flush the remaining operators in the stack to the output
void flushStack() {
    while (top >= 0) {
        printf("%c ", pop());
    }
}

int main() {
    printf("Enter an infix expression: ");
    
    // Start parsing the expression
    expr();
    
    // Flush the remaining operators in the stack
    flushStack();
    
    printf("\n");
    return 0;
}
