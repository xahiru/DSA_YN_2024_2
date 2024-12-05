// https://www.w3resource.com/c-programming-exercises/array/c-array-exercise-23.php
// Find sum of right diagonals of a matrix :                                                                     
// ---------------------------------------                                                                       
// Input the size of the square matrix : 2                                                                       
// Input elements in the first matrix :                                                                          
// element - [0],[0] : 1                                                                                         
// element - [0],[1] : 2                                                                                         
// element - [1],[0] : 3                                                                                         
// element - [1],[1] : 4                                                                                         
// The matrix is :                                                                                               
//    1   2                                                                                                      
//    3   4                                                                                                      
// Addition of the right Diagonal elements is :5


#include <stdio.h>

int main() {
    // Declare variables and matrix
    int i, j, arr1[50][50], sum = 0, n;

    // Display the purpose of the program
    printf("\n\nFind sum of right diagonals of a matrix :\n");
    printf("---------------------------------------\n");

    // Input the size of the square matrix
    printf("Input the size of the square matrix : ");
    scanf("%d", &n);

    // Input elements into the matrix and calculate sum of right diagonals
    printf("Input elements in the matrix :\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("element - [%d],[%d] : ", i, j);
            scanf("%d", &arr1[i][j]);
            // Calculate sum of elements on the right diagonal
            if (i == j) {
                sum = sum + arr1[i][j];
            }
        }
    }

    // Display the matrix
    printf("The matrix is :\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("% 4d", arr1[i][j]);
        }
        printf("\n");
    }

    // Display the sum of right diagonal elements
    printf("Addition of the right Diagonal elements is : %d\n", sum);

    return 0;
}
