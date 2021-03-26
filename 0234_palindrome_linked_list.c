/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


bool isPalindrome(struct ListNode* head){
    struct ListNode *sptr = head;
    struct ListNode *fptr = head;
    struct ListNode *pptr = NULL;
    struct ListNode *nptr = head;
    
    if (!head) {
        return true;
    }
    
    while(fptr && fptr->next) {
        fptr = fptr->next->next;
        /* Reverse the half part of linked list */
        nptr = sptr->next;
        sptr->next = pptr;
        pptr = sptr;
        sptr = nptr;
    }
    
    /* odd size */
    if (fptr) {
        sptr = sptr->next;
    }
    
    while (sptr) {
        if (pptr->val != sptr->val) {
            return false;
        }
        pptr = pptr->next;
        sptr = sptr->next;
    }
    return true;

}
