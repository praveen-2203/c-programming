#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** twoEditWords(char** queries, int queriesSize, char** dictionary, int dictionarySize, int* returnSize) {
    // Allocate memory for the maximum possible result array size
    char** result = (char**)malloc(queriesSize * sizeof(char*));
    int count = 0;
    int word_len = strlen(queries[0]);

    for (int i = 0; i < queriesSize; i++) {
        for (int j = 0; j < dictionarySize; j++) {
            int mismatches = 0;
            
            // Count mismatches between queries[i] and dictionary[j]
            for (int k = 0; k < word_len; k++) {
                if (queries[i][k] != dictionary[j][k]) {
                    mismatches++;
                    // Optimization: Break early if mismatches exceed 2
                    if (mismatches > 2) {
                        break;
                    }
                }
            }
            
            // If valid, allocate memory for the string copy and save it
            if (mismatches <= 2) {
                result[count] = (char*)malloc((word_len + 1) * sizeof(char));
                strcpy(result[count], queries[i]);
                count++;
                break; // Move to the next query word
            }
        }
    }

    *returnSize = count;
    return result;
}
