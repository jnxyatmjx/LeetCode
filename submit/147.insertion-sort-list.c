/*
 * @lc app=leetcode id=147 lang=c
 *
 * [147] Insertion Sort List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* insertionSortList(struct ListNode* head){
    
    struct ListNode hdump, *cur = &hdump; //for the new result list
    hdump.next=NULL;//very important
    
    while (head) {
        struct ListNode *t = head->next; // get first node from unsorted part
        
        cur = &hdump;
        while (cur->next && cur->next->val <= head->val) {
            cur = cur->next;
        }
        head->next = cur->next;
        cur->next = head;
        head = t;
    }
    return hdump.next;

}
// @lc code=end

