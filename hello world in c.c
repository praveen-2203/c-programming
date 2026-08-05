#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    char s[100];
    
    // Read a full line of string including spaces
    scanf("%[^\n]%*c", s);
      
    // Print the required outputs
    printf("Hello, World!\n");
    printf("%s\n", s);
    
    return 0;
}
