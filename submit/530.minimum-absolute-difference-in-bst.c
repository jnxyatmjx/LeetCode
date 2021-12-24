/*
 * @lc app=leetcode id=530 lang=c
 *
 * [530] Minimum Absolute Difference in BST
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

#define minl(a,b) \
({ __typeof__ (a) a_ = (a);\
__typeof__ (b) b_ = (b);\
 a_ < b_ ? a_ : b_;})

void in_ord(struct TreeNode* root,int* prev,int* min)
{
    if(root==NULL) return;
    in_ord(root->left,prev,min);

    if(*prev != -1)
        *min = minl(*min,root->val - *prev);//from parent to child path nodes

    *prev = root->val;

    in_ord(root->right,prev,min);
}

//from parent to child path nodes
int getMinimumDifference(struct TreeNode* root){
    int prev=-1, min=INT_MAX;
    in_ord(root,&prev,&min);
    return min;
}
// @lc code=end

