/*
 * @lc app=leetcode id=141 lang=c
 *
 * [141] Linked List Cycle
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
// fast and slow pointer can find middle node of this list (slow)
bool hasCycle(struct ListNode *head) {
    if(head == NULL) return false;  
    struct ListNode * fast=head, *slow=head;
    while(fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow) return true;
    }
    return false;
}
// @lc code=end

