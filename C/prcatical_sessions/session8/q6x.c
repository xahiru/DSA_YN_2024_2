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

// Function for fast transposition of a sparse matrix
void fastTranspose(tripletable a, tripletable *b) {
    int num[a.n];   // Array to store the count of non-zero elements in each column
    int cpot[a.n];  // Array to store the starting position of each column in the transposed matrix
    int p, q;

    // Step 1: Initialize num[] and cpot[]
    for (int col = 0; col < a.n; col++) {
        num[col] = 0; // Initialize counts to zero
    }

    // Count the number of non-zero elements in each column
    for (p = 0; p < a.t; p++) {
        num[a.data[p].j]++;
    }

    // Calculate the starting positions in the transposed matrix
    cpot[0] = 0; // First column starts at position 0
    for (int col = 1; col < a.n; col++) {
        cpot[col] = cpot[col - 1] + num[col - 1];
    }

    // Step 2: Perform the transposition
    b->m = a.n; // Transposed rows
    b->n = a.m; // Transposed columns
    b->t = a.t; // Same number of non-zero elements

    for (p = 0; p < a.t; p++) {
        int col = a.data[p].j; // Column index in the original matrix
        q = cpot[col];         // Find the position in the transposed matrix
        b->data[q].i = a.data[p].j;
        b->data[q].j = a.data[p].i;
        b->data[q].v = a.data[p].v;
        cpot[col]++;           // Update the position for the next element
    }
}

// Function to display the sparse matrix in triplet form
void displayTriplet(tripletable mat) {
    printf("Rows: %d, Columns: %d, Non-Zero Elements: %d\n", mat.m, mat.n, mat.t);
    for (int i = 0; i < mat.t; i++) {
        printf("(%d, %d, %d)\n", mat.data[i].i, mat.data[i].j, mat.data[i].v);
    }
}

int main() {
    tripletable a, b;

    // Input the sparse matrix dimensions and non-zero elements
    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d %d", &a.m, &a.n);

    printf("Enter the number of non-zero elements: ");
    scanf("%d", &a.t);

    printf("Enter the non-zero elements (row, column, value):\n");
    for (int i = 0; i < a.t; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d %d %d", &a.data[i].i, &a.data[i].j, &a.data[i].v);
    }

    // Display the original matrix
    printf("\nOriginal matrix in triplet form:\n");
    displayTriplet(a);

    // Perform fast transposition
    fastTranspose(a, &b);

    // Display the transposed matrix
    printf("\nTransposed matrix in triplet form:\n");
    displayTriplet(b);

    return 0;
}
