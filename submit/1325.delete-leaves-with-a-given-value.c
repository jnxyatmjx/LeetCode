/*
 * @lc app=leetcode id=1325 lang=c
 *
 * [1325] Delete Leaves With a Given Value
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
struct TreeNode* removeLeafNodes(struct TreeNode* root, int target){
    if(root==NULL) return NULL;
    root->left = removeLeafNodes(root->left,target);
    root->right = removeLeafNodes(root->right,target);

    //postorder delete tree node , after delete left and right node if the new leaf(old root) node have target, delete it
    return (root->left==NULL && root->right==NULL && root->val==target)? NULL: root;
}
// @lc code=end

