#include <stdio.h>
#include <string.h>

#define MAXSIZE 100  // Define a maximum size for the strings

typedef struct {
    char ch[MAXSIZE + 1];  // String array (1-based index, so we start from 1)
    int length;            // Length of the string
} SString;

// Naive string matching function
int Index(SString S, SString T, int pos) {
    int i = pos;  // Start position in S
    int j = 1;    // Start position in T

    while (i <= S.length && j <= T.length) {
        if (S.ch[i] == T.ch[j]) {
            ++i;
            ++j;
        } else {
            i = i - j + 2;  // Move i to the next starting position
            j = 1;          // Reset j to 1
        }
    }

    // If the entire pattern T has been matched, return the start index
    if (j > T.length) {
        return i - T.length;
    } else {
        return 0;  // No match found
    }
}

// Utility function to initialize a string
void initString(SString *str, const char *text) {
    str->length = strlen(text);
    for (int i = 1; i <= str->length; i++) {
        str->ch[i] = text[i - 1];
    }
}

int main() {
    SString S, T;

    // Initialize the main string S and the pattern string T
    initString(&S, "ababcabcabababd");
    initString(&T, "ababd");

    int position = 1;  // Start position in S (1-based index)
    int result = Index(S, T, position);

    if (result != 0) {
        printf("Pattern found at index %d\n", result);
    } else {
        printf("Pattern not found\n");
    }

    return 0;
}
