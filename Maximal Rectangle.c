#include <stdio.h>
#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

// Helper function to find the largest rectangle in a single histogram row
int findMaxHistogram(int* heights, int size) {
    int* stack = (int*)malloc((size + 1) * sizeof(int));
    int top = -1;
    int max_area = 0;
    
    for (int i = 0; i <= size; i++) {
        int current_height = (i == size) ? 0 : heights[i];
        
        while (top >= 0 && heights[stack[top]] > current_height) {
            int height = heights[stack[top--]];
            int width = (top == -1) ? i : (i - stack[top] - 1);
            max_area = MAX(max_area, height * width);
        }
        stack[++top] = i;
    }
    
    free(stack);
    return max_area;
}

int maximalRectangle(char** matrix, int matrixSize, int* matrixColSize) {
    if (matrixSize == 0 || matrixColSize[0] == 0) return 0;
    
    int rows = matrixSize;
    int cols = matrixColSize[0];
    
    int* heights = (int*)calloc(cols, sizeof(int));
    int max_rectangle = 0;
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == '1') {
                heights[j] += 1;
            } else {
                heights[j] = 0;
            }
        }
        // Calculate max area for the updated histogram configuration
        int area = findMaxHistogram(heights, cols);
        max_rectangle = MAX(max_rectangle, area);
    }
    
    free(heights);
    return max_rectangle;
}
