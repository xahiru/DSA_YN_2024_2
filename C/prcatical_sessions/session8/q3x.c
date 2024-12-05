#include <stdio.h>
#include <stdbool.h>

// Function to calculate sparsity
bool isSparseMatrix(int rows, int cols, int matrix[rows][cols]) {
    int non_zero_count = 0;
    int total_elements = rows * cols;

    // Count the number of non-zero elements
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                non_zero_count++;
            }
        }
    }

    // Calculate the sparse factor
    float sparse_factor = (float)non_zero_count / total_elements;

    // Output results
    printf("The matrix has %d non-zero elements.\n", non_zero_count);
    printf("The sparse factor (e) is: %.4f\n", sparse_factor);

    // Return whether the matrix is sparse
    return sparse_factor <= 0.05;
}

// Driver function to demonstrate usage
int main() {
    int rows, cols;

    // Input the dimensions of the matrix
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    // Declare the matrix
    int matrix[rows][cols];

    // Input the matrix elements
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }

    // Check if the matrix is sparse
    if (isSparseMatrix(rows, cols, matrix)) {
        printf("The matrix is a sparse matrix.\n");
    } else {
        printf("The matrix is not a sparse matrix.\n");
    }

    return 0;
}
