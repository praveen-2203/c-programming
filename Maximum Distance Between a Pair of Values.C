#include <stdio.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int maxDistance(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int i = 0, j = 0;
    int max_dist = 0;
    
    while (i < nums1Size && j < nums2Size) {
        if (nums1[i] <= nums2[j]) {
            max_dist = MAX(max_dist, j - i);
            j++;
        } else {
            i++;
        }
    }
    
    return max_dist;
}
