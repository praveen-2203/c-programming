#include <stdio.h>

long long countCommas(long long n) {
    long long total_commas = 0;
    long long tier = 1000;
    
    // Loop through each threshold (1,000, 1,000,000, etc.)
    while (n >= tier) {
        total_commas += (n - tier + 1);
        
        // Prevent overflow if tier * 1000 exceeds maximum long long limit
        if (tier > 9223372036854775LL / 1000) {
            break;
        }
        tier *= 1000;
    }
    
    return total_commas;
}
