#include <string.h>

int numberOfPoints(int** nums, int numsSize, int* numsColSize) {
    // Array to track covered points on the number line (1 to 100)
    int covered[102] = {0};
    
    // Mark all points covered by each car
    for (int i = 0; i < numsSize; i++) {
        int start = nums[i][0];
        int end = nums[i][1];
        for (int j = start; j <= end; j++) {
            covered[j] = 1;
        }
    }
    
    // Count the total number of unique marked points
    int count = 0;
    for (int i = 1; i <= 100; i++) {
        if (covered[i] == 1) {
            count++;
        }
    }
    
    return count;
}
