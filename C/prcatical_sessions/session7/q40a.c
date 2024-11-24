#include <stdio.h>
#include <string.h>

// Function to compute the LPS array
void computeLPSArray(char *pattern, int lps[]) {
    int length = 0; // Length of the previous longest prefix suffix
    int i = 1;
    lps[0] = 0; // LPS for the first character is always 0

    int m = strlen(pattern);

    // Loop to calculate LPS values for pattern[1] to pattern[m-1]
    while (i < m) {
        if (pattern[i] == pattern[length]) {
            length++;
            lps[i] = length;
            i++;
        } else {
            if (length != 0) {
                // Move to the previous LPS position
                length = lps[length - 1];
            } else {
                // No match
                lps[i] = 0;
                i++;
            }
        }
    }
}

int main() {
    char pattern[100];

    // Input the pattern string
    printf("Enter the string: ");
    scanf("%s", pattern);

    int m = strlen(pattern);
    int lps[m];

    // Calculate the LPS array
    computeLPSArray(pattern, lps);

    // Output the LPS array
    printf("LPS array for the string \"%s\":\n", pattern);
    for (int i = 0; i < m; i++) {
        printf("%d ", lps[i]);
    }
    printf("\n");

    return 0;
}
