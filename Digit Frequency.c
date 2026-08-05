#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char s[1001];
    if (scanf("%1000s", s) != 1) return 0;

    // Array to store frequencies of digits 0 to 9, initialized to 0
    int frequencies[10] = {0};

    // Iterate through the string character by character
    for (int i = 0; s[i] != '\0'; i++) {
        // Check if the current character is a digit
        if (s[i] >= '0' && s[i] <= '9') {
            frequencies[s[i] - '0']++;
        }
    }

    // Print the ten space-separated frequencies
    for (int i = 0; i < 10; i++) {
        printf("%d ", frequencies[i]);
    }
    printf("\n");

    return 0;
}
