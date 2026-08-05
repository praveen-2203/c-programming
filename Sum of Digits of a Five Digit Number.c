#include <stdio.h>

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    
    int sum = 0;
    
    // Loop until all digits are processed
    while (n > 0) {
        sum += n % 10; // Extract the last digit and add to sum
        n = n / 10;    // Remove the last digit from the number
    }
    
    printf("%d\n", sum);
    return 0;
}
