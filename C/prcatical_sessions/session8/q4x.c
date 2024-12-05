#include <stdio.h>

#define maxsize 10000

typedef int datatype;

typedef struct {
    int i, j;         // Row and column indices
    datatype v;       // Value at the given position
} triple;

typedef struct {
    triple data[maxsize]; // Array to store non-zero elements
    int m, n, t;          // Rows, columns, and number of non-zero elements
} tripletable;

// Function to transpose a sparse matrix
void transmatrix(tripletable a, tripletable *b) {
    int p, q, col;
    b->m = a.n;   // Transposed matrix rows
    b->n = a.m;   // Transposed matrix columns
    b->t = a.t;   // Same number of non-zero elements
    q = 0;        // Index for the transposed matrix data

    for (col = 0; col < a.n; col++) { // Loop through columns of original matrix
        for (p = 0; p < a.t; p++) {   // Loop through all non-zero elements
            if (a.data[p].j == col) { // If element belongs to the current column
                b->data[q].i = a.data[p].j; // Transpose row index
                b->data[q].j = a.data[p].i; // Transpose column index
                b->data[q].v = a.data[p].v; // Copy the value
                q++;
            }
        }
    }
}

int main() {
    tripletable a, b;
    int i;

    // Input the sparse matrix dimensions and non-zero elements
    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d %d", &a.m, &a.n);

    printf("Enter the number of non-zero elements: ");
    scanf("%d", &a.t);

    printf("Enter the non-zero elements (row, column, value):\n");
    for (i = 0; i < a.t; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d %d %d", &a.data[i].i, &a.data[i].j, &a.data[i].v);
    }

    // Transpose the matrix
    transmatrix(a, &b);

    // Output the transposed matrix
    printf("\nTransposed matrix non-zero elements (row, column, value):\n");
    for (i = 0; i < b.t; i++) {
        printf("%d %d %d\n", b.data[i].i, b.data[i].j, b.data[i].v);
    }

    return 0;
}
