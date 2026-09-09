#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

bool isValid(char* s) {
    int len = strlen(s);
    
    // Allocate space for the stack on the stack frame
    char* stack = (char*)malloc(len * sizeof(char));
    int top = -1;
    
    for (int i = 0; i < len; i++) {
        char ch = s[i];
        
        // Push opening brackets onto the stack
        if (ch == '(' || ch == '[' || ch == '{') {
            stack[++top] = ch;
        } 
        // Validate closing brackets
        else {
            // Stack is empty means no matching opening bracket
            if (top == -1) {
                free(stack);
                return false;
            }
            
            char open = stack[top--];
            if ((ch == ')' && open != '(') ||
                (ch == ']' && open != '[') ||
                (ch == '}' && open != '{')) {
                free(stack);
                return false;
            }
        }
    }
    
    bool valid = (top == -1);
    free(stack);
    return valid;
}
