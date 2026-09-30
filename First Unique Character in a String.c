#include <stdio.h>
int firstUniqChar(char* s) {
    int digit = 0;
    int count=0;
    while (s[digit] != '\0')
    {
        count =0;
        for (int i = 0;s[i] != '\0'; i++) {
            if (s[digit] == s[i] && i != digit) {
                count++;
                break;
            }
        }
        if (count == 0) {
            return digit;
        }
        digit++;
    }
    return -1;
}
