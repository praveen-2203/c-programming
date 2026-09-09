#include <string.h>

int strStr(char* haystack, char* needle) {
    // Find the first occurrence of needle in haystack
    char* ptr = strstr(haystack, needle);
    
    // If ptr is NULL, the needle was not found
    if (ptr == NULL) {
        return -1;
    }
    
    // Calculate index position by subtracting the base address of haystack
    return (int)(ptr - haystack);
}
