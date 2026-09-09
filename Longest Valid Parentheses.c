#include <string.h>
#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int longestValidParentheses(char* s) {
    int len = strlen(s);
    if (len == 0) return 0;
    
    // Allocate memory for the index stack
    int* stack = (int*)malloc((len + 1) * sizeof(int));
    int top = -1;
    
    // Push the initial base boundary anchor (-1)
    stack[++top] = -1;
    int max_len = 0;
    
    for (int i = 0; i < len; i++) {
        if (s[i] == '(') {
            stack[++top] = i;
        } else {
            top--; // Pop
            if (top == -1) {
                // Stack is empty; push current index as the new base anchor
                stack[++top] = i;
            } else {
                // Valid sequence detected
                max_len = MAX(max_len, i - stack[top]);
            }
        }
    }
    
    free(stack);
    return max_len;
}
