#include <stdio.h>
#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int largestRectangleArea(int* heights, int heightsSize) {
    // Create an array that holds a trailing 0 element
    int* extended_heights = (int*)malloc((heightsSize + 1) * sizeof(int));
    for (int i = 0; i < heightsSize; i++) {
        extended_heights[i] = heights[i];
    }
    extended_heights[heightsSize] = 0; // Trailing 0 to flush the stack
    
    // Allocate memory for the monotonic index stack
    int* stack = (int*)malloc((heightsSize + 1) * sizeof(int));
    int top = -1;
    int max_area = 0;
    
    for (int i = 0; i <= heightsSize; i++) {
        // While stack is not empty and current height is strictly less than top element height
        while (top >= 0 && extended_heights[stack[top]] > extended_heights[i]) {
            int height = extended_heights[stack[top--]];
            int width = (top == -1) ? i : (i - stack[top] - 1);
            max_area = MAX(max_area, height * width);
        }
        stack[++top] = i; // Push current index
    }
    
    free(extended_heights);
    free(stack);
    return max_area;
}
