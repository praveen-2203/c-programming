#include <stdbool.h>

bool isPalindrome(int x) {
    // Negative numbers and numbers ending in 0 (except 0 itself) 
    // can never be palindromes.
    if (x < 0 || (x % 10 == 0 && x != 0)) {
        return false;
    }

    int reversed_half = 0;
    while (x > reversed_half) {
        // Extract the last digit and append it to the reversed half
        reversed_half = reversed_half * 10 + (x % 10);
        // Remove the last digit from the original number
        x /= 10;
    }

    // For even number of digits: x should equal reversed_half (e.g., 1221 -> x=12, reversed_half=12)
    // For odd number of digits: the middle digit is at the end of reversed_half, 
    // so we get rid of it by dividing by 10 (e.g., 12321 -> x=12, reversed_half=123)
    return x == reversed_half || x == reversed_half / 10;
}
