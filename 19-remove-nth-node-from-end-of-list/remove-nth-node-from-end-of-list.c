/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 * 
 * (Note: The definition above is commented out because LeetCode handles it)
 */

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    // 1. Create a dummy node to eliminate edge cases (e.g., removing the head)
    struct ListNode dummy;
    dummy.val = 0;
    dummy.next = head;
    
    struct ListNode* fast = &dummy;
    struct ListNode* slow = &dummy;
    
    // 2. Advance fast pointer so that the gap between fast and slow is n nodes
    for (int i = 0; i <= n; i++) {
        fast = fast->next;
    }
    
    // 3. Move both pointers together until fast reaches the end
    while (fast != NULL) {
        fast = fast->next;
        slow = slow->next;
    }
    
    // 4. slow->next is the node to be deleted
    struct ListNode* nodeToDelete = slow->next;
    slow->next = slow->next->next;
    
    // Free memory of the deleted node
    free(nodeToDelete);
    
    // Return the real head of the modified list
    return dummy.next;
}
