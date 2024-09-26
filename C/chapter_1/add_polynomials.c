#include <stdio.h>
#include <stdlib.h>

typedef struct Term {
    float coef;  // Coefficient
    int expn;    // Exponent
} Term;

typedef struct Node {
    Term data;
    struct Node *next;
} Node, *Polynomial;

// Function to compare exponents
int cmp(int expn1, int expn2) {
    if (expn1 < expn2) return -1;
    if (expn1 > expn2) return 1;
    return 0;
}

// Function to add two polynomials
void AddPolyn(Polynomial *Pa, Polynomial *Pb) {
    Polynomial ha = *Pa, hb = *Pb;
    Node *qa = ha->next, *qb = hb->next;

    while (qa && qb) {
        Term a = qa->data, b = qb->data;
        switch (cmp(a.expn, b.expn)) {
            case -1:  // Current exponent of qa is smaller than qb's
                ha = qa;
                qa = ha->next;
                break;
            case 0:   // Same exponent, add coefficients
                qa->data.coef = a.coef + b.coef;
                if (qa->data.coef != 0) {
                    ha = qa;
                } else {
                    ha->next = qa->next;
                    free(qa);
                }
                hb->next = qb->next;
                free(qb);
                qa = ha->next;
                qb = hb->next;
                break;
            case 1:   // Current exponent of qa is larger than qb's
                hb->next = qb->next;
                qb->next = qa;
                ha->next = qb;
                qb = hb->next;
                break;
        }
    }
    if (qb) ha->next = qb;  // Append the remaining part of Pb if any
    free(*Pb);
}

// Helper function to create a new term node
Node* createNode(float coef, int expn) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data.coef = coef;
    newNode->data.expn = expn;
    newNode->next = NULL;
    return newNode;
}

// Function to print the polynomial
void printPolynomial(Polynomial p) {
    Node *current = p->next;  // Skip the head node
    while (current) {
        printf("%.1fx^%d ", current->data.coef, current->data.expn);
        if (current->next) printf("+ ");
        current = current->next;
    }
    printf("\n");
}

// Example usage
int main() {
    // Create two example polynomials for addition
    Polynomial Pa = createNode(0, 0);  // Dummy head node
    Pa->next = createNode(3.0, 3);
    Pa->next->next = createNode(2.0, 2);

    Polynomial Pb = createNode(0, 0);  // Dummy head node
    Pb->next = createNode(1.0, 3);
    Pb->next->next = createNode(4.0, 0);

    printf("Pa: ");
    printPolynomial(Pa);
    printf("Pb: ");
    printPolynomial(Pb);

    AddPolyn(&Pa, &Pb);

    printf("After addition, Pa: ");
    printPolynomial(Pa);

    return 0;
}
