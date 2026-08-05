#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int next_permutation(int n, char **s) {
    // 1. Find the largest index i such that s[i] < s[i+1]
    int i = n - 2;
    while (i >= 0 && strcmp(s[i], s[i + 1]) >= 0) {
        i--;
    }
    
    // If no such index exists, we are at the last permutation
    if (i < 0) {
        return 0;
    }
    
    // 2. Find the largest index j greater than i such that s[i] < s[j]
    int j = n - 1;
    while (strcmp(s[i], s[j]) >= 0) {
        j--;
    }
    
    // 3. Swap strings at index i and index j
    char *temp = s[i];
    s[i] = s[j];
    s[j] = temp;
    
    // 4. Reverse the suffix starting from index i + 1 to the end of the array
    int left = i + 1;
    int right = n - 1;
    while (left < right) {
        temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        left++;
        right--;
    }
    
    // Successfully found the next permutation
    return 1;
}

int main()
{
	char **s;
	int n;
	scanf("%d", &n);
	s = calloc(n, sizeof(char*));
	for (int i = 0; i < n; i++)
	{
		s[i] = calloc(11, sizeof(char));
		scanf("%s", s[i]);
	}
	do
	{
		for (int i = 0; i < n; i++)
			printf("%s%c", s[i], i == n - 1 ? '\n' : ' ');
	} while (next_permutation(n, s));
	for (int i = 0; i < n; i++)
		free(s[i]);
	free(s);
	return 0;
}
