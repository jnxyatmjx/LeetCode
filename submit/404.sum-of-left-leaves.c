/*
 * @lc app=leetcode id=404 lang=c
 *
 * [404] Sum of Left Leaves
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


int sumOfLeftLeaves(struct TreeNode* root){
    if (root == NULL) return 0;

    //if root have a LEFT leaf node
    if (root->left && root->left->left==NULL && root->left->right==NULL) 
    {
        return root->left->val + sumOfLeftLeaves(root->right);
    }
    int lefv = sumOfLeftLeaves(root->left);
    int rigv = sumOfLeftLeaves(root->right);
    return lefv + rigv;
    //return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
}
// @lc code=end

