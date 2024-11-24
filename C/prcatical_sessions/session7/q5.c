#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define str_size 100 // Declare the maximum size of the string

int main() {
    char str[str_size]; // Declare a character array for the string
    int i, wrd; // Declare variables for iteration and word count
	
    printf("\n\nCount the total number of words in a string :\n"); // Display information about the task
    printf("------------------------------------------------------\n");
    printf("Input the string : ");

    // Read a string from the standard input (keyboard) using fgets()
    fgets(str, sizeof str, stdin);

    i = 0; // Initialize the iterator
    wrd = 1; // Initialize the word count to 1 (assuming at least one word exists in the string)

    /* Loop to count words in the string */
    while (str[i] != '\0') { // Loop until the end of the string ('\0' character is encountered)
        /* Check whether the current character is white space, new line, or tab character */
        if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t') {
            wrd++; // Increment the word count when a space, newline, or tab is found
        }

        i++; // Move to the next character in the string
    }

    printf("Total number of words in the string is : %d\n", wrd - 1); // Display the total number of words counted
	
	return 0; // Return 0 to indicate successful execution of the program
}
