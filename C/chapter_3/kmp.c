#include <stdio.h>
#include <string.h>

void computeNextArray(char *pattern, int next[], int m) {
    int j = 0;  // length of the previous longest prefix suffix
    next[0] = 0; // first value is always 0

    for (int i = 1; i < m; i++) {
        while (j > 0 && pattern[i] != pattern[j]) {
            j = next[j - 1];
        }
        if (pattern[i] == pattern[j]) {
            j++;
        }
        next[i] = j;
    }
}

void KMP(char *text, char *pattern) {
    int n = strlen(text);
    int m = strlen(pattern);

    int next[m];
    computeNextArray(pattern, next, m);

    int j = 0;  // index for pattern
    for (int i = 0; i < n; i++) {
        // Adjust the position of j for mismatches
        while (j > 0 && text[i] != pattern[j]) {
            j = next[j - 1];
        }

        if (text[i] == pattern[j]) {
            j++;
        }

        if (j == m) {  // match found
            printf("Pattern found at index %d\n", i - m + 1);
            j = next[j - 1];
        }
    }
}

int main() {
    char text[] = "ababcabcabababd";
    char pattern[] = "ababd";

    KMP(text, pattern);

    return 0;
}
