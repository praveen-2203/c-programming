#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char *s;
    s = malloc(1024 * sizeof(char));
    if (scanf("%[^\n]", s) != 1) return 0;
    s = realloc(s, strlen(s) + 1);
    
    // Loop through each character of the string
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == ' ') {
            printf("\n"); // Print a new line when a space is found
        } else {
            printf("%c", s[i]); // Print the character
        }
    }
    printf("\n"); // Print trailing newline for formatting
    
    free(s);
    return 0;
}
