/*
 * @lc app=leetcode id=783 lang=c
 *
 * [783] Minimum Distance Between BST Nodes
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
({  __typeof__ (a) a_ = (a);\
    __typeof__ (b) b_ = (b);\
    a_ < b_ ? a_ : b_;})

int minDiffInBST(struct TreeNode* root){
    int prev = -1,min = INT_MAX;
    in_ord(root,&prev,&min);
    return min;
}

//from parent to child nodes path
void in_ord(struct TreeNode* root,int* prev,int* min)
{
    if(root == NULL) return ;
    in_ord(root->left,prev,min);

    if(*prev != -1)//Not the first node
    {
        *min = minl(*min,root->val - *prev);
    }
    *prev = root->val;

    in_ord(root->right,prev,min);
}
// @lc code=end

