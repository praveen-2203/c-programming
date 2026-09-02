#include <string.h>
#include <stdlib.h>

// Helper function to expand around a given center point
// Returns the length of the palindrome found
int expandAroundCenter(char* s, int left, int right, int length) {
    while (left >= 0 && right < length && s[left] == s[right]) {
        left--;
        right++;
    }
    // Length of the palindrome is right - left - 1 
    // because left and right have decremented/incremented past the matching boundaries
    return right - left - 1;
}

char* longestPalindrome(char* s) {
    if (s == NULL || strlen(s) == 0) {
        char* empty = (char*)malloc(1 * sizeof(char));
        empty[0] = '\0';
        return empty;
    }

    int length = strlen(s);
    int start = 0;
    int max_len = 0;

    for (int i = 0; i < length; i++) {
        // Expand for odd length palindromes (e.g., "aba")
        int len1 = expandAroundCenter(s, i, i, length);
        // Expand for even length palindromes (e.g., "abba")
        int len2 = expandAroundCenter(s, i, i + 1, length);
        
        // Find the maximum of the two expansion choices
        int len = (len1 > len2) ? len1 : len2;
        
        // If a longer palindrome is found, update start and max_len
        if (len > max_len) {
            max_len = len;
            // Set start index based on the center point 'i'
            start = i - (len - 1) / 2;
        }
    }

    // Allocate memory for the substring (+1 for null terminator)
    char* result = (char*)malloc((max_len + 1) * sizeof(char));
    strncpy(result, s + start, max_len);
    result[max_len] = '\0'; // Explicitly add null terminator

    return result;
}
