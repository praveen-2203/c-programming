#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
    if (numsSize == 0 || k == 0) {
        *returnSize = 0;
        return NULL;
    }
    
    int totalWindows = numsSize - k + 1;
    int* result = (int*)malloc(totalWindows * sizeof(int));
    *returnSize = totalWindows;
    
    // Deque to store indices of array elements.
    // In the worst case, it won't hold more than numsSize elements.
    int* deque = (int*)malloc(numsSize * sizeof(int));
    int head = 0; // Front of the deque
    int tail = 0; // Back of the deque
    
    for (int i = 0; i < numsSize; i++) {
        // 1. Remove indices that are out of the current window's left bound
        if (head < tail && deque[head] <= i - k) {
            head++;
        }
        
        // 2. Maintain a decreasing order in the deque.
        // Remove indices of elements from the back that are smaller than the current element.
        while (head < tail && nums[deque[tail - 1]] <= nums[i]) {
            tail--;
        }
        
        // 3. Append the current element's index to the back of the deque
        deque[tail++] = i;
        
        // 4. Once the window reaches size k, the maximum element is at the front
        if (i >= k - 1) {
            result[i - k + 1] = nums[deque[head]];
        }
    }
    
    free(deque);
    return result;
}
