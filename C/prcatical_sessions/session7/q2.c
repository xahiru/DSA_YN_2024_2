#include <stdio.h>
#include <stdlib.h>

int main() {
    char str[100]; /* Declares a string of size 100 */
    int l = 0; // Initialize a variable to store the length of the string
	
    printf("\n\nFind the length of a string :\n"); // Display information about the task
    printf("---------------------------------\n"); 	
    printf("Input the string : ");

    // Read a string from the standard input (keyboard) using fgets()
    fgets(str, sizeof str, stdin);

    // Loop to calculate the length of the string
    while (str[l] != '\0') {
        l++; // Increment the length counter until the null terminator '\0' is encountered
    }

    printf("Length of the string is : %d\n\n", l - 1); // Display the length of the string
	
	return 0; // Return 0 to indicate successful execution of the program
}
