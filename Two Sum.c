#include <stdlib.h>

// Structure for hash map nodes
struct HashNode {
    int key;
    int value;
    struct HashNode* next;
};

// Simple hash function handling negative keys
int hash(int key, int size) {
    int h = key % size;
    return h < 0 ? h + size : h;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    // 1. Set the return size to 2 as we are returning exactly two indices
    *returnSize = 2;
    int* result = (int*)malloc(2 * sizeof(int));
    
    // 2. Determine hash table size (using numsSize for basic load balancing)
    int tableSize = numsSize;
    struct HashNode** hashTable = (struct HashNode**)calloc(tableSize, sizeof(struct HashNode*));

    // 3. Iterate through the array
    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];
        int complementHashIndex = hash(complement, tableSize);
        
        // 4. Check if the complement exists in the hash table
        struct HashNode* curr = hashTable[complementHashIndex];
        while (curr != NULL) {
            if (curr->key == complement) {
                result[0] = curr->value;
                result[1] = i;
                
                // Free allocated memory for the hash table before returning
                for (int j = 0; j < tableSize; j++) {
                    struct HashNode* node = hashTable[j];
                    while (node != NULL) {
                        struct HashNode* temp = node;
                        node = node->next;
                        free(temp);
                    }
                }
                free(hashTable);
                return result;
            }
            curr = curr->next;
        }
        
        // 5. If not found, insert the current number and index into the hash table
        int currentHashIndex = hash(nums[i], tableSize);
        struct HashNode* newNode = (struct HashNode*)malloc(sizeof(struct HashNode));
        newNode->key = nums[i];
        newNode->value = i;
        newNode->next = hashTable[currentHashIndex];
        hashTable[currentHashIndex] = newNode;
    }

    // Clean up memory in case no solution is found (though the problem guarantees one)
    free(hashTable);
    return NULL;
}
