/*
 * @lc app=leetcode id=109 lang=c
 *
 * [109] Convert Sorted List to Binary Search Tree
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* createNode(int val)
{
    struct TreeNode* node = (struct TreeNode*)calloc(1,sizeof(struct TreeNode));
    node->val = val;
    return node;
}

struct TreeNode* bltTree(struct ListNode* head,struct ListNode* tail)
{
    if(head == tail) return NULL;
    
    // fast and slow pointer can find middle node of this list
    struct ListNode* fast = head,*slow = head;
    while(fast != tail && fast->next != tail)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    //find the middle node of this list ,slow IS

    struct TreeNode* node = createNode(slow->val);

    //process left subtree with subleft list 
    node->left = bltTree(head,slow);

    //process right subtree with subright list
    node->right = bltTree(slow->next,tail);

    return node;
}


struct TreeNode* sortedListToBST(struct ListNode* head){
    if(head == NULL) return NULL;
    return bltTree(head,NULL);
}
// @lc code=end

