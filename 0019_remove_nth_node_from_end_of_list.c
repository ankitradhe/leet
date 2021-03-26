/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    
    struct ListNode *pnext = head;
    struct ListNode *cur = head;
    struct ListNode *prev = NULL;

    int count  = 1;
    if (n < 1) {
        return head;
    }
    
    while (count <= n) {
        pnext = pnext->next;
        count++;
    }
    
    while (pnext) {
        prev = cur;
        cur = cur->next;
        pnext = pnext->next;
    }
    
    /* This is place for deleting the node */
    if (prev) {
        prev->next = cur->next;
    } else {
        head = cur->next;
    }
    
    free(cur);
    return head;
}
