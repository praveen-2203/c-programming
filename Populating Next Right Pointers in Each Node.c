#include <stdio.h>

struct Node* connect(struct Node* root) {
    if (!root) {
        return NULL;
    }
    
    struct Node* leftmost = root;
    
    // Loop level by level down the tree
    while (leftmost->left != NULL) {
        struct Node* curr = leftmost;
        
        // Traverse across the current level using 'next' pointers
        while (curr != NULL) {
            // Connection 1: Children of the same parent
            curr->left->next = curr->right;
            
            // Connection 2: Children between adjacent parents
            if (curr->next != NULL) {
                curr->right->next = curr->next->left;
            }
            
            // Move to the next parent node on the same level
            curr = curr->next;
        }
        
        // Move to the start of the next level down
        leftmost = leftmost->left;
    }
    
    return root;
}
