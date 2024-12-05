#include <stdio.h>

int main() {
    // Given values
    int base_address = 1000; // Base address of the array
    int element_size = 4;    // Size of each element in bytes
    int rows = 4, columns = 5; // Dimensions of the array
    int i = 2, j = 3;        // Indices of the element to find

    // Calculate the address
    int address = base_address + element_size * (i * columns + j);

    // Output the result
    printf("The address of A[%d][%d] is: %d\n", i, j, address);

    return 0;
}
