#include <string.h>

int lengthOfLongestSubstring(char* s) {
    // Array to store the last seen index of each ASCII character
    int last_seen[256];
    
    // Initialize all positions to -1 (not seen yet)
    memset(last_seen, -1, sizeof(last_seen));
    
    int max_len = 0;
    int start = 0;
    
    for (int end = 0; s[end] != '\0'; end++) {
        unsigned char current_char = (unsigned char)s[end];
        
        // If the character was seen inside the current window, move start pointer
        if (last_seen[current_char] >= start) {
            start = last_seen[current_char] + 1;
        }
        
        // Update the last seen index of the character
        last_seen[current_char] = end;
        
        // Calculate current window length and update max_len
        int current_len = end - start + 1;
        if (current_len > max_len) {
            max_len = current_len;
        }
    }
    
    return max_len;
}
