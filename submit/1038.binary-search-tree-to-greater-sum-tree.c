/*
 * @lc app=leetcode id=1038 lang=c
 *
 * [1038] Binary Search Tree to Greater Sum Tree
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

//same to 538

//traversal from RIGHT to ROOT to LEFT
void inorter_tra(struct TreeNode* root, int* res)
{
    if(root == NULL) return ;

    inorter_tra(root->right,res);
    
    *res += root->val;
    root->val = *res;

    inorter_tra(root->left,res);
}

struct TreeNode* bstToGst(struct TreeNode* root){

    int sum = 0;
    inorter_tra(root,&sum);
    return root;
}
// @lc code=end

