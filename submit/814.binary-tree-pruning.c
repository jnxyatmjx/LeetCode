/*
 * @lc app=leetcode id=814 lang=c
 *
 * [814] Binary Tree Pruning
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


struct TreeNode* pruneTree(struct TreeNode* root){
    if(root == NULL)
        return NULL;
    
    //postorder tree , reduce duplicate calculate
    root->left = pruneTree(root->left);
    root->right = pruneTree(root->right);

    //if it is leaf node and value is 0, just remove
    if(root->left == NULL && root->right == NULL && root->val == 0)
        return NULL;

    return root;
}
// @lc code=end

