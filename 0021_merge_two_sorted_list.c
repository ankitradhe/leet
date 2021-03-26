/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *temp = NULL;
    struct ListNode *retl = NULL;
    
    if (!l1) {
        return l2;
    } else if (!l2) {
        return l1;
    }
    
    retl = l2;
    temp = l2;
    if (l1->val <= l2->val) {
        retl = l1;
        temp = l1;
        l1 = l2;
    }
    l2 = temp->next;
    
    while(l2) {
        if (l1->val >= l2->val) {
            temp = l2;
            l2=l2->next;
        } else {
            temp->next = l1;
            temp = l1;
            l1 = l2;
            l2 = temp->next;
        }
    }
    temp->next = l1;
    
    return retl;
}
