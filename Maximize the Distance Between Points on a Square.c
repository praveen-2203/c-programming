#include <stdio.h>
#include <stdlib.h>

// Helper comparator function to sort long long values
int compareLL(const void* a, const void* b) {
    long long arg1 = *(const long long*)a;
    long long arg2 = *(const long long*)b;
    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
}

// Manual implementation of lower_bound (finds first element >= target)
int lower_bound(long long* nums, int size, long long target) {
    int low = 0, high = size;
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] >= target) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    return low;
}

// Helper function to check if a specific min_dist is achievable
int can_place(long long min_dist, long long* nums, int size, int k, long long total_perimeter) {
    for (int s = 0; s < size; s++) {
        long long start = nums[s];
        long long max_end = start + total_perimeter - min_dist;
        long long curr = start;
        int possible = 1;

        for (int i = 0; i < k - 1; ++i) {
            int idx = lower_bound(nums, size, curr + min_dist);
            if (idx == size || nums[idx] > max_end) {
                possible = 0;
                break;
            }
            curr = nums[idx];
        }
        if (possible) return 1;
    }
    return 0;
}

int maxDistance(int side, int** points, int pointsSize, int* pointsColSize, int k) {
    long long total_perimeter = 4LL * side;
    long long* nums = (long long*)malloc(pointsSize * sizeof(long long));

    // Step 1: Flatten the 2D boundary coordinates into a linear 1D spectrum
    for (int i = 0; i < pointsSize; i++) {
        long long x = points[i][0];
        long long y = points[i][1];
        
        if (x == 0) {
            nums[i] = y;
        } else if (y == side) {
            nums[i] = side + x;
        } else if (x == side) {
            nums[i] = 3LL * side - y;
        } else {
            nums[i] = 4LL * side - x;
        }
    }

    // Sort the 1D positions
    qsort(nums, pointsSize, sizeof(long long), compareLL);

    // Step 2: Binary Search for maximum achievable minimum distance
    long long low = 1, high = side;
    long long ans = 1;

    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (can_place(mid, nums, pointsSize, k, total_perimeter)) {
            ans = mid;
            low = mid + 1; // Try to maximize the gap further
        } else {
            high = mid - 1; // Shrink target gap
        }
    }

    free(nums);
    return (int)ans;
}
