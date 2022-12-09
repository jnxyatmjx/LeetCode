/*
 * @lc app=leetcode id=100 lang=c
 *
 * [100] Same Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


bool isSameTree(struct TreeNode* p, struct TreeNode* q){
    if(p==NULL && q==NULL) return true;

    //if( (!p && q) || (p && !q) || (p->val != q->val)) return false;
    if( (p==NULL || q==NULL) || (p->val != q->val)) return false;

    return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
}
// @lc code=end

