#include <stdio.h>
#include <stdlib.h>

struct Node* connect(struct Node* root) {
    if (!root) {
        return NULL;
    }
    
    struct Node* curr = root;  // Head of the current parent level
    
    while (curr != NULL) {
        struct Node dummy;     // Stack-allocated dummy node for the child level
        dummy.next = NULL;
        struct Node* tail = &dummy;
        
        // Traverse across the current parent level
        while (curr != NULL) {
            if (curr->left != NULL) {
                tail->next = curr->left;
                tail = tail->next;
            }
            if (curr->right != NULL) {
                tail->next = curr->right;
                tail = tail->next;
            }
            curr = curr->next;  // Move to the next parent node
        }
        
        // Move down to the next level's head
        curr = dummy.next;
    }
    
    return root;
}
