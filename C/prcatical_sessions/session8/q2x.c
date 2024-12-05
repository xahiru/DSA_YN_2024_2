#include <stdio.h>

int main() {
    int dimensions[10];  // Array to store dimensions (supports up to 10 dimensions)
    int base_address, element_size, num_dimensions, index[10];
    int offset = 0;

    // Input the number of dimensions
    printf("Enter the number of dimensions: ");
    scanf("%d", &num_dimensions);

    // Input the size of each dimension
    printf("Enter the size of each dimension:\n");
    for (int i = 0; i < num_dimensions; i++) {
        printf("Dimension %d size: ", i + 1);
        scanf("%d", &dimensions[i]);
    }

    // Input the base address and size of each element
    printf("Enter the base address of the array: ");
    scanf("%d", &base_address);
    printf("Enter the size of each element in bytes: ");
    scanf("%d", &element_size);

    // Input the indices of the desired element
    printf("Enter the indices of the element to find:\n");
    for (int i = 0; i < num_dimensions; i++) {
        printf("Index for dimension %d: ", i + 1);
        scanf("%d", &index[i]);
    }

    // Compute the offset
    int stride = 1;
    for (int i = num_dimensions - 1; i >= 0; i--) {
        offset += index[i] * stride;
        stride *= dimensions[i];
    }

    // Calculate the address
    int address = base_address + element_size * offset;

    // Output the result
    printf("The address of the element is: %d\n", address);

    return 0;
}
