#include <stdio.h>
#include <limits.h>

int buyChoco(int* prices, int pricesSize, int money) {
    int min1 = INT_MAX;
    int min2 = INT_MAX;
    
    // Scan array once to extract the lowest two price variables
    for (int i = 0; i < pricesSize; i++) {
        if (prices[i] < min1) {
            min2 = min1;
            min1 = prices[i];
        } else if (prices[i] < min2) {
            min2 = prices[i];
        }
    }
    
    int min_cost = min1 + min2;
    
    // Return leftover budget if affordable, else fallback to initial balance
    return (min_cost <= money) ? (money - min_cost) : money;
}
