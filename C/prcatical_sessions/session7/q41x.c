#include <stdio.h>
#include <string.h>

// Function to compute the LPS array
void computeLPSArray(char *pattern, int m, int lps[]) {
    int length = 0; // Length of the previous longest prefix suffix
    int i = 1;

    lps[0] = 0; // LPS for the first character is always 0

    // Loop to calculate LPS values for pattern[1] to pattern[m-1]
    while (i < m) {
        if (pattern[i] == pattern[length]) {
            length++;
            lps[i] = length;
            i++;
        } else {
            if (length != 0) {
                length = lps[length - 1]; // Move to the previous LPS position
            } else {
                lps[i] = 0; // No prefix suffix match
                i++;
            }
        }
    }
}

// KMP search function
void KMPSearch(char *text, char *pattern) {
    int n = strlen(text);    // Length of the text
    int m = strlen(pattern); // Length of the pattern

    // Create and compute the LPS array
    int lps[m];
    computeLPSArray(pattern, m, lps);

    int i = 0; // Index for text[]
    int j = 0; // Index for pattern[]

    // Traverse the text to search for the pattern
    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        if (j == m) {
            printf("Pattern found at index %d\n", i - j);
            j = lps[j - 1]; // Move to the previous LPS position
        } else if (i < n && pattern[j] != text[i]) {
            // Mismatch after j matches
            if (j != 0) {
                j = lps[j - 1]; // Use the LPS array
            } else {
                i++;
            }
        }
    }
}

int main() {
    char text[100], pattern[100];

    // Input the text and pattern
    printf("Enter the text: ");
    scanf("%s", text);
    printf("Enter the pattern: ");
    scanf("%s", pattern);

    // Search for the pattern in the text using KMP algorithm
    KMPSearch(text, pattern);

    return 0;
}
