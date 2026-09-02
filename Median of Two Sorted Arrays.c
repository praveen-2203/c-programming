#include <limits.h>

// Helper macro to find minimum and maximum
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    // Ensure nums1 is the smaller array to optimize binary search range
    if (nums1Size > nums2Size) {
        return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);
    }
    
    int m = nums1Size;
    int n = nums2Size;
    int low = 0;
    int high = m;
    int half_len = (m + n + 1) / 2;
    
    while (low <= high) {
        int i = low + (high - low) / 2;
        int j = half_len - i;
        
        // Edge boundaries for nums1
        int maxLeft1 = (i == 0) ? INT_MIN : nums1[i - 1];
        int minRight1 = (i == m) ? INT_MAX : nums1[i];
        
        // Edge boundaries for nums2
        int maxLeft2 = (j == 0) ? INT_MIN : nums2[j - 1];
        int minRight2 = (j == n) ? INT_MAX : nums2[j];
        
        // Check if we found the correct partition point
        if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
            // If total length is odd, the median is the maximum of the left side
            if ((m + n) % 2 != 0) {
                return (double)MAX(maxLeft1, maxLeft2);
            }
            // If total length is even, the median is the average of the middle two values
            return (double)(MAX(maxLeft1, maxLeft2) + MIN(minRight1, minRight2)) / 2.0;
        } 
        // If maxLeft1 is too large, we need to shift our partition left in nums1
        else if (maxLeft1 > minRight2) {
            high = i - 1;
        } 
        // If maxLeft2 is too large, we need to shift our partition right in nums1
        else {
            low = i + 1;
        }
    }
    
    return 0.0;
}
