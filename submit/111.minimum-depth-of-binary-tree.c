/*
 * @lc app=leetcode id=111 lang=c
 *
 * [111] Minimum Depth of Binary Tree
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

#define minl(a,b)\
({ __typeof__ (a) a_ = (a);\
    __typeof__ (b) b_ = (b);\
    a_ < b_ ? a_ : b_;})

int minDepth(struct TreeNode* root){
        
        if(!root) return 0;

        int left = minDepth(root->left);
        int right = minDepth(root->right);
        
        if(left == 0) return right + 1;
        if(right == 0) return left + 1;

        return 1 + minl(left,right);
}
// @lc code=end

