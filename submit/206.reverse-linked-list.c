/*
 * @lc app=leetcode id=206 lang=c
 *
 * [206] Reverse Linked List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head){
    struct ListNode *res = NULL;
    while(head)
    {
        struct ListNode *cur = head->next;
        head->next = res;
        res = head;
        head = cur;
    }
    return res;
}
// @lc code=end

