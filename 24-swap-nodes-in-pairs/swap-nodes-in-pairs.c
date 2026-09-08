/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* swapPairs(struct ListNode* head) {
    
    // 0 or 1 node: no swapping needed
    if (head == NULL || head->next == NULL) {
        return head;
    }

    // First two nodes
    struct ListNode* first = head;
    struct ListNode* second = head->next;

    // Swap the first pair
    first->next = swapPairs(second->next);
    second->next = first;

    // Second becomes the new head
    return second;
}