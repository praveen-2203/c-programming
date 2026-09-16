/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * struct NestedInteger;
 *
 * bool NestedIntegerIsInteger(struct NestedInteger *);
 * int NestedIntegerGetInteger(struct NestedInteger *);
 * struct NestedInteger **NestedIntegerGetList(struct NestedInteger *);
 * int NestedIntegerGetListSize(struct NestedInteger *);
 */

struct NestedIterator {
    int *vals;   // Array to store flattened integers
    int size;    // Total count of integers
    int cur;     // Current iteration index
};

// Helper function to recursively flatten the nested structure
void flatten(struct NestedIterator *iter, struct NestedInteger **nestedList, int nestedListSize) {
    for (int i = 0; i < nestedListSize; i++) {
        if (NestedIntegerIsInteger(nestedList[i])) {
            // Store the single integer
            iter->vals[iter->size++] = NestedIntegerGetInteger(nestedList[i]);
        } else {
            // Recursively process the inner sublist
            flatten(iter, NestedIntegerGetList(nestedList[i]), NestedIntegerGetListSize(nestedList[i]));
        }
    }
}

struct NestedIterator *nestedIterCreate(struct NestedInteger **nestedList, int nestedListSize) {
    struct NestedIterator *iter = (struct NestedIterator *)malloc(sizeof(struct NestedIterator));
    
    // Allocate space based on problem constraints (max 500 lists/integers)
    // Allocating a safe upper bound buffer
    iter->vals = (int *)malloc(sizeof(int) * 100000); 
    iter->size = 0;
    iter->cur = 0;
    
    // Flatten the entire structure starting from the root list
    flatten(iter, nestedList, nestedListSize);
    
    return iter;
}

bool nestedIterHasNext(struct NestedIterator *iter) {
    return iter->cur < iter->size;
}

int nestedIterNext(struct NestedIterator *iter) {
    return iter->vals[iter->cur++];
}

/** Deallocates memory previously allocated for the iterator */
void nestedIterFree(struct NestedIterator *iter) {
    if (iter) {
        free(iter->vals);
        free(iter);
    }
}
