/*
 * @lc app=leetcode id=142 lang=c
 *
 * [142] Linked List Cycle II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    if(head == NULL) return NULL;

    struct ListNode *slow = head,*fast = head;
    while(fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow)
        {
            for(slow = head;slow != fast;slow = slow->next,fast = fast->next)
            {
                ;
            }
            return slow;
        }
    }
    return NULL;
}
// @lc code=end

