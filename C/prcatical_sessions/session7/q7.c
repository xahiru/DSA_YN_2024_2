#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define str_size 100 // Declare the maximum size of the string

int main() {
    char str[str_size]; // Declare a character array for the string
    int alp, digit, splch, i; // Declare variables for alphabets, digits, special characters, and iteration
    alp = digit = splch = i = 0; // Initialize counters to zero

    printf("\n\nCount total number of alphabets, digits, and special characters :\n"); // Display information about the task
    printf("--------------------------------------------------------------------\n");
    printf("Input the string : ");
    fgets(str, sizeof str, stdin); // Read a string from the standard input (keyboard)

    /* Checks each character of the string */
    while (str[i] != '\0') {
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) {
            alp++; // Increment the alphabet count if the character is an alphabet
        } else if (str[i] >= '0' && str[i] <= '9') {
            digit++; // Increment the digit count if the character is a digit
        } else {
            splch++; // Increment the special character count for all other characters
        }
        i++; // Move to the next character in the string
    }

    // Display the counts of alphabets, digits, and special characters in the string
    printf("Number of Alphabets in the string is : %d\n", alp);
    printf("Number of Digits in the string is : %d\n", digit);
    printf("Number of Special characters in the string is : %d\n\n", splch);
	
	return 0; // Return 0 to indicate successful execution of the program
}
