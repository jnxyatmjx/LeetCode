/*
 * @lc app=leetcode id=617 lang=c
 *
 * [617] Merge Two Binary Trees
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


struct TreeNode* mergeTrees(struct TreeNode* root1, struct TreeNode* root2){
    //DFS
    if(root1 == NULL ) 
        return root2;

    if(root2 == NULL)
        return root1;
       
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = root1->val + root2->val;
    root->left = mergeTrees(root1->left,root2->left); 
    root->right = mergeTrees(root1->right,root2->right); 

    return root;
}
// @lc code=end

