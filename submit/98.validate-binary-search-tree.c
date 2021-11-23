/*
 * @lc app=leetcode id=98 lang=c
 *
 * [98] Validate Binary Search Tree
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
bool preorder_traver(struct TreeNode* root,struct TreeNode* min,struct TreeNode* max)
{
    if(root==NULL) return true;

    if(min!=NULL && root->val <= min->val) return false;
    if(max!=NULL && root->val >= max->val) return false;
    
    return preorder_traver(root->left,min,root) && preorder_traver(root->right,root,max);
}

bool isValidBST(struct TreeNode* root){

    return preorder_traver(root,NULL,NULL);
}

// @lc code=end

