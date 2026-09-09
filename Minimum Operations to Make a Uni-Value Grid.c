#include <stdlib.h>

// Comparator function for qsort
int compareInts(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int minOperations(int** grid, int gridSize, int* gridColSize, int x) {
    int m = gridSize;
    int n = gridColSize[0];
    int total_elements = m * n;
    
    // Allocate a flat 1D array
    int* flat = (int*)malloc(total_elements * sizeof(int));
    int k = 0;
    
    int target_rem = grid[0][0] % x;
    
    // Flatten the grid while checking remainder feasibility
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if ((grid[i][j] % x + x) % x != (target_rem + x) % x) {
                free(flat);
                return -1; // Impossible to make them uni-value
            }
            flat[k++] = grid[i][j];
        }
    }
    
    // Sort the elements to find the median
    qsort(flat, total_elements, sizeof(int), compareInts);
    
    int median = flat[total_elements / 2];
    int operations = 0;
    
    // Calculate total operations relative to the median element
    for (int i = 0; i < total_elements; i++) {
        operations += abs(flat[i] - median) / x;
    }
    
    free(flat);
    return operations;
}
