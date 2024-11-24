#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to find the longest palindromic substring
char* test(char* text) {
    // Check if the string is empty
    if (!text[0])
        return "No string found";

    char *text_pt = text;
    char *sub_start = text;
    char *start_pos;
    char *end_pos;
    int max_length = 1;

    // Loop through the string
    while (*text_pt) {
        start_pos = text_pt;
        end_pos = text_pt;

        // Find the longest palindrome for the current character
        while (*(end_pos + 1) && *(end_pos + 1) == *end_pos) {
            end_pos++;
        }
        text_pt = end_pos + 1;

        // Expand the palindrome substring on both sides
        while (*(end_pos + 1) && (start_pos > text) && *(end_pos + 1) == *(start_pos - 1)) {
            start_pos--;
            end_pos++;
        }

        // Update the maximum length of the palindrome substring
        if (end_pos - start_pos + 1 > max_length) {
            max_length = end_pos - start_pos + 1;
            sub_start = start_pos;
        }
    }

    // Allocate memory for the result and copy the palindrome substring
    char *result = (char *)calloc(max_length + 1, sizeof(char));
    strncpy(result, sub_start, max_length);
    return result;
}

int main() {
    // Example strings for testing
    //char text[50] = "abcdcsd";
    char text[50] = "abcdcsdfabbccb";
    //char text[50] = "";

    printf("Original string: %s", text);
    printf("\nLongest Palindromic Substring from the said string? %s ", test(text));
}
