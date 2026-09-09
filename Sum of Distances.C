#include <stdlib.h>

// Structure to pair each element's value with its original index
typedef struct {
    int val;
    int idx;
} Element;

// Comparator function to sort by value, and then by original index
int compareElements(const void* a, const void* b) {
    Element* e1 = (Element*)a;
    Element* e2 = (Element*)b;
    if (e1->val != e2->val) {
        return (e1->val < e2->val) ? -1 : 1;
    }
    return (e1->idx < e2->idx) ? -1 : 1;
}

long long* distance(int* nums, int numsSize, int* returnSize) {
    // Allocate output array initialized to 0s
    long long* ans = (long long*)calloc(numsSize, sizeof(long long));
    *returnSize = numsSize;

    // Track original indices by bundling value and index together
    Element* arr = (Element*)malloc(numsSize * sizeof(Element));
    for (int i = 0; i < numsSize; i++) {
        arr[i].val = nums[i];
        arr[i].idx = i;
    }

    // Sort to group matching values consecutively
    qsort(arr, numsSize, sizeof(Element), compareElements);

    // Process every grouped segment of identical elements
    int start = 0;
    while (start < numsSize) {
        int end = start;
        while (end < numsSize && arr[end].val == arr[start].val) {
            end++;
        }
        
        int group_size = end - start;
        // Calculate prefix/suffix sums only if duplicates exist
        if (group_size > 1) {
            long long total_sum = 0;
            for (int i = start; i < end; i++) {
                total_sum += arr[i].idx;
            }
            
            long long running_left_sum = 0;
            for (int k = 0; k < group_size; k++) {
                int curr_idx = arr[start + k].idx;
                long long running_right_sum = total_sum - running_left_sum - curr_idx;
                
                long long left_count = k;
                long long right_count = group_size - 1 - k;
                
                // Prefix distance formula
                long long left_dist = (left_count * curr_idx) - running_left_sum;
                long long right_dist = running_right_sum - (right_count * curr_idx);
                
                ans[curr_idx] = left_dist + right_dist;
                
                // Track accumulated index sums to the left
                running_left_sum += curr_idx;
            }
        }
        start = end; // Step to the next unique value tier
    }

    free(arr);
    return ans;
}
