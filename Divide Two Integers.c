#include <stdlib.h>
#include <limits.h>

int divide(int dividend, int divisor) {
    // Edge case overflow
    if (dividend == INT_MIN && divisor == -1) {
        return INT_MAX;
    }
    
    // Determine sign using XOR
    int negative = (dividend < 0) ^ (divisor < 0);
    
    // Convert to long long absolute values to avoid integer overflow
    long long a = llabs(dividend);
    long long b = llabs(divisor);
    long long quotient = 0;
    
    // Exponential subtraction using bit-shifts
    while (a >= b) {
        long long temp_divisor = b;
        long long multiple = 1;
        
        while (a >= (temp_divisor << 1)) {
            temp_divisor <<= 1;
            multiple <<= 1;
        }
        
        a -= temp_divisor;
        quotient += multiple;
    }
    
    return negative ? -quotient : quotient;
}
