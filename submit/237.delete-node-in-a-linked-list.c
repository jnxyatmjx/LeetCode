/*
 * @lc app=leetcode id=237 lang=c
 *
 * [237] Delete Node in a Linked List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode(struct ListNode* node) {
    
    *node = *(node->next);
    
   /* struct ListNode * temp;
    if(node==NULL) return;
    temp = node->next;
    
    node->val = temp->val;
    node->next = temp->next;
    free(temp); */
}
// @lc code=end

