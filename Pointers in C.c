#include <stdio.h>
#include <stdlib.h> // Required for the abs() function

void update(int *a, int *b) {
    // Store original values locally
    int val_a = *a;
    int val_b = *b;
    
    // Update the value at pointer a to the sum
    *a = val_a + val_b;
    
    // Update the value at pointer b to the absolute difference
    *b = abs(val_a - val_b);
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    if (scanf("%d %d", &a, &b) == 2) {
        update(pa, pb);
        printf("%d\n%d\n", a, b);
    }
    return 0;
}
