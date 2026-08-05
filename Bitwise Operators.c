#include <stdio.h>

void calculate_the_maximum(int n, int k) {
    int max_and = 0;
    int max_or = 0;
    int max_xor = 0;

    // Nested loops to find all unique pairs (i, j)
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int and_result = i & j;
            int or_result = i | j;
            int xor_result = i ^ j;

            // Check if results are less than k and greater than current maximums
            if (and_result < k && and_result > max_and) {
                max_and = and_result;
            }
            if (or_result < k && or_result > max_or) {
                max_or = or_result;
            }
            if (xor_result < k && xor_result > max_xor) {
                max_xor = xor_result;
            }
        }
    }

    // Print the maximum values on three separate lines
    printf("%d\n%d\n%d\n", max_and, max_or, max_xor);
}

int main() {
    int n, k;
    if (scanf("%d %d", &n, &k) != 2) return 0;
    
    calculate_the_maximum(n, k);
    
    return 0;
}
