#include <stdbool.h>

bool isPowerOfTwo(int n) {
    // Check if n is positive and its bitwise intersection with (n - 1) clears out to 0
    return n > 0 && (n & (n - 1)) == 0;
}
