#include <stdlib.h>

// Comparator function to sort based on (bCost - aCost)
int compareCosts(const void* a, const void* b) {
    int* costA = *(int**)a;
    int* costB = *(int**)b;
    
    int diffA = costA[1] - costA[0];
    int diffB = costB[1] - costB[0];
    
    return (diffA < diffB) ? -1 : (diffA > diffB);
}

int twoCitySchedCost(int** costs, int costsSize, int* costsColSize) {
    // Sort rows based on our difference metric
    qsort(costs, costsSize, sizeof(int*), compareCosts);
    
    int total_cost = 0;
    int n = costsSize / 2;
    
    // First n people go to City B, last n people go to City A
    for (int i = 0; i < n; i++) {
        total_cost += costs[i][1];       // City B
        total_cost += costs[i + n][0];   // City A
    }
    
    return total_cost;
}
