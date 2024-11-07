#include <stdio.h>
#include <string.h>

#define BASE 256    // Base for the hash function (number of characters in the input alphabet)
#define MOD 101     // A prime number used as modulus to reduce hash collisions

// Rabin-Karp algorithm function
void rabinKarp(char *text, char *pattern) {
    int n = strlen(text);       // Length of the text
    int m = strlen(pattern);    // Length of the pattern
    int patternHash = 0;        // Hash value for the pattern
    int textHash = 0;           // Hash value for the current window of text
    int h = 1;

    // Calculate h = BASE^(m-1) % MOD
    for (int i = 0; i < m - 1; i++)
        h = (h * BASE) % MOD;

    // Calculate the initial hash values for the pattern and the first window of text
    for (int i = 0; i < m; i++) {
        patternHash = (BASE * patternHash + pattern[i]) % MOD;
        textHash = (BASE * textHash + text[i]) % MOD;
    }

    // Slide the pattern over the text one character at a time
    for (int i = 0; i <= n - m; i++) {
        // Check if the current window hash matches the pattern hash
        if (patternHash == textHash) {
            // Hashes match, now check the actual characters
            int j;
            for (j = 0; j < m; j++) {
                if (text[i + j] != pattern[j])
                    break;
            }
            // If the pattern matches
            if (j == m)
                printf("Pattern found at index %d\n", i);
        }

        // Calculate the hash for the next window (remove leading char, add trailing char)
        if (i < n - m) {
            textHash = (BASE * (textHash - text[i] * h) + text[i + m]) % MOD;

            // Convert negative hash value to positive
            if (textHash < 0)
                textHash = (textHash + MOD);
        }
    }
}

int main() {
    char text[] = "abcxabcdabxabcdabcdabcy";
    char pattern[] = "abcdabcy";

    printf("Text: %s\n", text);
    printf("Pattern: %s\n", pattern);
    
    // Run the Rabin-Karp algorithm
    rabinKarp(text, pattern);

    return 0;
}
