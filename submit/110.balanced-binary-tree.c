/*
 * @lc app=leetcode id=110 lang=c
 *
 * [110] Balanced Binary Tree
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

#define maxl(a,b)\
({ __typeof__ (a) a_ = (a);\
    __typeof__ (b) b_ = (b);\
    a_ > b_ ? a_ : b_;})


bool isBalanced(struct TreeNode* root){

    return ishelp(root) != -1;
}

int ishelp(struct TreeNode* root)
{
    if(root==NULL) return 0;
    
    int lft = ishelp(root->left);
    int rgt = ishelp(root->right);

    if(lft==-1 || rgt==-1 || abs(lft-rgt)>1)
        return -1;
    
    return maxl(lft,rgt) + 1;//return the subtree's max length
}
// @lc code=end

