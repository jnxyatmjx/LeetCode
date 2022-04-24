/*
 * @lc app=leetcode id=236 lang=c
 *
 * [236] Lowest Common Ancestor of a Binary Tree
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
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    
    if(root==NULL || p==root || q==root )
        return root;

    struct TreeNode* lft = lowestCommonAncestor(root->left,p,q);
    struct TreeNode* rgt = lowestCommonAncestor(root->right,p,q);

    if(lft ==NULL) return rgt;
    if(rgt ==NULL) return lft;
    return root;
}
// @lc code=end

