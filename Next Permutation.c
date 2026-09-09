#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void reverse(int* nums, int left, int right) {
    while (left < right) {
        swap(&nums[left], &nums[right]);
        left++;
        right--;
    }
}

void nextPermutation(int* nums, int numsSize) {
    int i = numsSize - 2;
    
    // Step 1: Find the first decreasing element from the right
    while (i >= 0 && nums[i] >= nums[i + 1]) {
        i--;
    }
    
    // Step 2: If pivot is found, find its successor and swap
    if (i >= 0) {
        int j = numsSize - 1;
        while (nums[j] <= nums[i]) {
            j--;
        }
        swap(&nums[i], &nums[j]);
    }
    
    // Step 3: Reverse the elements to the right of index i
    reverse(nums, i + 1, numsSize - 1);
}
