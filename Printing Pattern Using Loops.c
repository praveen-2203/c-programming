#include <stdio.h>

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    
    int size = 2 * n - 1;
    
    // Loop through each row
    for (int i = 0; i < size; i++) {
        // Loop through each column
        for (int j = 0; j < size; j++) {
            // Find the minimum distance to any of the 4 edges
            int min_i = i < size - 1 - i ? i : size - 1 - i;
            int min_j = j < size - 1 - j ? j : size - 1 - j;
            int min_dist = min_i < min_j ? min_i : min_j;
            
            // The value decreases as you move inward from n
            printf("%d ", n - min_dist);
        }
        printf("\n");
    }
    
    return 0;
}
