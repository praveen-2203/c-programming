#include <stdio.h>
#include <stdlib.h>

int furthestDistanceFromOrigin(char* moves) {
    int count_L = 0;
    int count_R = 0;
    int count_underscore = 0;
    
    // Count characters in a single pass
    for (int i = 0; moves[i] != '\0'; i++) {
        if (moves[i] == 'L') {
            count_L++;
        } else if (moves[i] == 'R') {
            count_R++;
        } else {
            count_underscore++;
        }
    }
    
    return abs(count_L - count_R) + count_underscore;
}
