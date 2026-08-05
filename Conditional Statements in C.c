#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int n;
    
    // Read the single integer input from stdin
    if (scanf("%d", &n) != 1) {
        return 0;
    }

    // Array lookup representing lowercase English words for numbers 1 to 9
    // Index 0 is intentionally left empty so index matches the number directly
    char *words[] = {
        "", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"
    };

    // Check conditions and print the corresponding output string
    if (n >= 1 && n <= 9) {
        printf("%s\n", words[n]);
    } else if (n > 9) {
        printf("Greater than 9\n");
    }

    return 0;
}
