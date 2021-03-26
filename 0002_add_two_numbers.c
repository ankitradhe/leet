/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){

    int carry_frwd = 0;
    int sum = 0;
    struct ListNode *l3 = NULL;
    struct ListNode *tl3 = NULL;
    struct ListNode *cl3 = NULL;
    
    while((l1 != NULL) && (l2 != NULL)) {
        sum = l1->val + l2->val + carry_frwd;

        tl3 = (struct ListNode*)malloc(sizeof(struct ListNode));
        tl3->next = NULL;
        tl3->val = sum%10;
        carry_frwd = sum/10;
        
        if (cl3) {
            cl3->next = tl3;
        } else {
            l3 = tl3;
        }
        cl3 = tl3;
        l1 = l1->next;
        l2 = l2->next;
    }
    
    /* l1 has less items than l2 */
    while ((l1 == NULL) && (l2 != NULL)) {
        sum = l2->val + carry_frwd;
        
        tl3 = (struct ListNode*)malloc(sizeof(struct ListNode));
        tl3->next = NULL;
        tl3->val = sum%10;
        carry_frwd = sum/10;
        cl3->next = tl3;
        cl3 = tl3;
        l2 = l2->next;
    }
    
    /* l1 has more items than l2 */
    while ((l1 != NULL) && (l2 == NULL)) {
        sum = l1->val + carry_frwd;
        
        tl3 = (struct ListNode*)malloc(sizeof(struct ListNode));
        tl3->next = NULL;
        tl3->val = sum%10;
        carry_frwd = sum/10;
        cl3->next = tl3;
        cl3 = tl3;
        l1 = l1->next;
    }
    
    if (carry_frwd) {
        tl3 = (struct ListNode*)malloc(sizeof(struct ListNode));
        tl3->next = NULL;
        tl3->val = carry_frwd;
        cl3->next = tl3;
        
    }
    
    return l3;
}
