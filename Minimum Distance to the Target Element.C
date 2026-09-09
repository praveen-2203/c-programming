#include <stdlib.h>
#include <math.h>

int getMinDistance(int* nums, int numsSize, int target, int start) {
    int min_dist = 10000; // Array length is at most 1000, so 10000 acts as infinity
    
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == target) {
            int current_dist = abs(i - start);
            if (current_dist < min_dist) {
                min_dist = current_dist;
            }
        }
    }
    
    return min_dist;
}
