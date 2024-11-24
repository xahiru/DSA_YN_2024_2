#include <stdio.h>
#include <string.h>

void printSubstrings(char str[]) {
    int length = strlen(str);

    // Loop to generate all substrings
    for (int i = 0; i < length; i++) {
        for (int j = i; j < length; j++) {
            // Print the substring from str[i] to str[j]
            for (int k = i; k <= j; k++) {
                printf("%c", str[k]);
            }
            printf("\n");
        }
    }
}

int main() {
    char str[100];

    // Input the string
    printf("Enter a string: ");
    scanf("%s", str);

    // Display substrings
    printf("Original string: %s\n", str);
    printf("Substrings:\n");
    printSubstrings(str);

    return 0;
}
