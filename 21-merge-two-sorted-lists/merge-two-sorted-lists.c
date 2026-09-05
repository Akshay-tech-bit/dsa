/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    
    // Dummy node banaya
    struct ListNode dummy;
    struct ListNode* current = &dummy;

    dummy.next = NULL;

    // Jab tak dono lists mein nodes hain
    while (list1 != NULL && list2 != NULL) {

        if (list1->val <= list2->val) {
            current->next = list1;
            list1 = list1->next;
        }
        else {
            current->next = list2;
            list2 = list2->next;
        }

        current = current->next;
    }

    // Jo list bach gayi hai usko attach karo
    if (list1 != NULL) {
        current->next = list1;
    }
    else {
        current->next = list2;
    }

    return dummy.next;
}