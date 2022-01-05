/*
 * @lc app=leetcode id=2 lang=c
 *
 * [2] Add Two Numbers
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* node(int val)
{
    struct ListNode* xv = (struct ListNode*)calloc(sizeof(struct ListNode) ,1);
    xv->val = val;
    return xv;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode dumph, *cur = &dumph;

    int cary = 0;
    while(cary>0 || l1!=NULL || l2!=NULL)
    {
        cary += (l1!=NULL) ? l1->val: 0;
        cary += (l2!=NULL) ? l2->val: 0;
        cur->next = node(cary%10);
        cur = cur->next;

        cary /= 10;
        if(l1) l1=l1->next;
        if(l2) l2=l2->next;
    }
    return dumph.next;

}
// @lc code=end

