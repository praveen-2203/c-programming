#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Helper function to count distinct characters in a string
int count_distinct(const char* s) {
    int flags[26] = {0};
    int distinct = 0;
    while (*s) {
        if (!flags[*s - 'a']) {
            flags[*s - 'a'] = 1;
            distinct++;
        }
        s++;
    }
    return distinct;
}

// 1. Lexicographical non-decreasing order
int lexicographic_sort(const char* a, const char* b) {
    return strcmp(a, b);
}

// 2. Lexicographical non-increasing (reverse) order
int lexicographic_sort_reverse(const char* a, const char* b) {
    return strcmp(b, a);
}

// 3. Sort by number of distinct characters, tie-break lexicographically
int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    int count_a = count_distinct(a);
    int count_b = count_distinct(b);
    if (count_a != count_b) {
        return count_a - count_b;
    }
    return strcmp(a, b);
}

// 4. Sort by length, tie-break lexicographically
int sort_by_length(const char* a, const char* b) {
    int len_a = strlen(a);
    int len_b = strlen(b);
    if (len_a != len_b) {
        return len_a - len_b;
    }
    return strcmp(a, b);
}

// Custom sorting function implementing Bubble Sort
void string_sort(const char **arr, const int cnt, int (*cmp_func)(const char* a, const char* b)) {
    for (int i = 0; i < cnt - 1; i++) {
        for (int j = 0; j < cnt - i - 1; j++) {
            // If cmp_func returns positive (> 0), elements are out of order
            if (cmp_func(arr[j], arr[j + 1]) > 0) {
                const char *temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() 
{
    int n;
    scanf("%d", &n);
  
    char** arr;
	arr = (char**)malloc(n * sizeof(char*));
  
    for(int i = 0; i < n; i++){
        *(arr + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }
  
    string_sort(arr, n, lexicographic_sort);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");

    string_sort(arr, n, sort_by_length);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);    
    printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");
}
