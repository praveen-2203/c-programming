#include <stdbool.h>

bool reachingPoints(int sx, int sy, int tx, int ty) {
    // Work backwards while both target coordinates are strictly greater than the source
    while (tx > sx && ty > sy) {
        if (tx > ty) {
            tx %= ty;
        } else {
            ty %= tx;
        }
    }
    
    // Now either tx <= sx or ty <= sy (or both)
    
    // Case 1: tx matches sx exactly
    // We only need to reduce ty down to sy by subtracting tx (which equals sx)
    if (tx == sx && ty >= sy) {
        return (ty - sy) % tx == 0;
    }
    
    // Case 2: ty matches sy exactly
    // We only need to reduce tx down to sx by subtracting ty (which equals sy)
    if (ty == sy && tx >= sx) {
        return (tx - sx) % ty == 0;
    }
    
    // If neither base condition is satisfied, it's impossible
    return false;
}
