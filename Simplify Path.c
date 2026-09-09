#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* simplifyPath(char* path) {
    int len = strlen(path);
    
    // Allocate space for the stack (array of directory names)
    char** stack = (char**)malloc(len * sizeof(char*));
    int top = -1;
    
    // Tokenize the path string using '/' as delimiter
    char* token = strtok(path, "/");
    while (token != NULL) {
        if (strcmp(token, ".") == 0 || strcmp(token, "") == 0) {
            // Current directory, do nothing
        } else if (strcmp(token, "..") == 0) {
            // Go up a directory level if stack is not empty
            if (top >= 0) {
                top--;
            }
        } else {
            // Valid directory name, push onto stack
            stack[++top] = token;
        }
        token = strtok(NULL, "/");
    }
    
    // Reconstruct the simplified path string
    char* result = (char*)malloc((len + 2) * sizeof(char));
    result[0] = '\0';
    
    if (top == -1) {
        strcpy(result, "/");
    } else {
        for (int i = 0; i <= top; i++) {
            strcat(result, "/");
            strcat(result, stack[i]);
        }
    }
    
    free(stack);
    return result;
}
