#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    // Read the size of the array
    if (scanf("%d", &n) != 1) return 0;

    // Dynamically allocate memory for n integers
    int *arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        return 1; // Memory allocation failed
    }

    int sum = 0;
    // Read elements into the array and add them to the sum
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    // Print the calculated sum
    printf("%d\n", sum);

    // Free the dynamically allocated memory
    free(arr);

    return 0;
}
