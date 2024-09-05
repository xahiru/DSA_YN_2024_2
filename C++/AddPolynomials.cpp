#include <iostream>
using namespace std;

struct Term {
    float coef;  // Coefficient
    int expn;    // Exponent
};

struct Node {
    Term data;
    Node *next;

    Node(float coef = 0, int expn = 0) {
        data.coef = coef;
        data.expn = expn;
        next = nullptr;
    }
};

typedef Node* Polynomial;

// Function to compare exponents
int cmp(int expn1, int expn2) {
    if (expn1 < expn2) return -1;
    if (expn1 > expn2) return 1;
    return 0;
}

// Function to add two polynomials
void AddPolyn(Polynomial &Pa, Polynomial &Pb) {
    Polynomial ha = Pa, hb = Pb;
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
                    delete qa;
                }
                hb->next = qb->next;
                delete qb;
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
    delete Pb;
}

// Helper function to add a new term to the polynomial
void addTerm(Polynomial &poly, float coef, int expn) {
    Node *newNode = new Node(coef, expn);
    Node *current = poly;
    while (current->next) {
        current = current->next;
    }
    current->next = newNode;
}

// Function to print the polynomial
void printPolynomial(Polynomial poly) {
    Node *current = poly->next;  // Skip the head node
    while (current) {
        cout << current->data.coef << "x^" << current->data.expn;
        if (current->next) cout << " + ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    // Create two example polynomials for addition
    Polynomial Pa = new Node();  // Dummy head node
    addTerm(Pa, 3.0, 3);
    addTerm(Pa, 2.0, 2);

    Polynomial Pb = new Node();  // Dummy head node
    addTerm(Pb, 1.0, 3);
    addTerm(Pb, 4.0, 0);

    cout << "Pa: ";
    printPolynomial(Pa);
    cout << "Pb: ";
    printPolynomial(Pb);

    AddPolyn(Pa, Pb);

    cout << "After addition, Pa: ";
    printPolynomial(Pa);

    return 0;
}
