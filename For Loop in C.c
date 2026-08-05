#include <stdio.h>

int main() {
    int a, b;
    if (scanf("%d\n%d", &a, &b) != 2) return 0;

    // Array lookup for numbers 1 to 9 (index 0 is left empty or unused)
    char *words[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    for (int n = a; n <= b; n++) {
        if (n >= 1 && n <= 9) {
            printf("%s\n", words[n]);
        } else if (n > 9) {
            if (n % 2 == 0) {
                printf("even\n");
            } else {
                printf("odd\n");
            }
        }
    }

    return 0;
}
