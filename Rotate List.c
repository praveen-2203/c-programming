#include <stdio.h>

struct ListNode* rotateRight(struct ListNode* head, int k) {
    if (head == NULL || head->next == NULL || k == 0) {
        return head;
    }
    
    // Step 1: Calculate length and track down the tail node
    int length = 1;
    struct ListNode* tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
        length++;
    }
    
    // Step 2: Form a circular loop ring
    tail->next = head;
    
    // Step 3: Normalize k using modulo
    k = k % length;
    int steps_to_new_tail = length - k;
    
    // Step 4: Advance to the new tail element position
    struct ListNode* new_tail = head;
    for (int i = 0; i < steps_to_new_tail - 1; i++) {
        new_tail = new_tail->next;
    }
    
    // Step 5: Sever the circular link and retrieve the new head
    struct ListNode* new_head = new_tail->next;
    new_tail->next = NULL;
    
    return new_head;
}
