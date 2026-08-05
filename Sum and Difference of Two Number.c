#include <stdio.h>

int main() {
    int int1, int2;
    float float1, float2;
    
    // Read two integers from the first line
    scanf("%d %d", &int1, &int2);
    
    // Read two float numbers from the second line
    scanf("%f %f", &float1, &float2);
    
    // Print sum and difference of the integers
    printf("%d %d\n", int1 + int2, int1 - int2);
    
    // Print sum and difference of the floats rounded to one decimal place
    printf("%.1f %.1f\n", float1 + float2, float1 - float2);
    
    return 0;
}
