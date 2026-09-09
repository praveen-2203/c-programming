#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes) {
    qsort(nums, numsSize, sizeof(int), compare);
    
    int capacity = 16;
    int** result = (int**)malloc(capacity * sizeof(int*));
    *returnColumnSizes = (int*)malloc(capacity * sizeof(int));
    int count = 0;
    
    for (int i = 0; i < numsSize - 3; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        
        for (int j = i + 1; j < numsSize - 2; j++) {
            if (j > i + 1 && nums[j] == nums[j - 1]) continue;
            
            int left = j + 1;
            int right = numsSize - 1;
            
            while (left < right) {
                // Use long long to avoid overflow when summing large elements
                long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];
                
                if (sum == target) {
                    if (count >= capacity) {
                        capacity *= 2;
                        result = (int**)realloc(result, capacity * sizeof(int*));
                        *returnColumnSizes = (int*)realloc(*returnColumnSizes, capacity * sizeof(int));
                    }
                    
                    result[count] = (int*)malloc(4 * sizeof(int));
                    result[count][0] = nums[i];
                    result[count][1] = nums[j];
                    result[count][2] = nums[left];
                    result[count][3] = nums[right];
                    (*returnColumnSizes)[count] = 4;
                    count++;
                    
                    left++;
                    right--;
                    
                    while (left < right && nums[left] == nums[left - 1]) left++;
                    while (left < right && nums[right] == nums[right + 1]) right--;
                } else if (sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }
    }
    
    *returnSize = count;
    return result;
}
