/*
 * @lc app=leetcode id=104 lang=c
 *
 * [104] Maximum Depth of Binary Tree
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

#define maxl(a,b) \
({ __typeof__ (a) a_ = (a);\
    __typeof__ (b) b_ = (b);\
    a_ > b_ ? a_ : b_;})

int maxDepth(struct TreeNode* root){
    if (!root) return 0;

    int lef = maxDepth(root->left);
    int rig = maxDepth(root->right);
    
    return 1 + maxl(lef,rig);

    //return 1 + maxl(maxDepth(root->left),maxDepth(root->right));
}
// @lc code=end

