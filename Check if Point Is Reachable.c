#include <stdbool.h>

// Helper function to find the greatest common divisor using the Euclidean algorithm
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

bool isReachable(int targetX, int targetY) {
    int g = gcd(targetX, targetY);
    
    // A number 'g' is a power of 2 if it is greater than 0 
    // and has exactly one bit set in binary representation: (g & (g - 1)) == 0
    return (g & (g - 1)) == 0;
}
