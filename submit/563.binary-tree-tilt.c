/*
 * @lc app=leetcode id=563 lang=c
 *
 * [563] Binary Tree Tilt
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
int findTilt(struct TreeNode* root){
    int res = 0;
    dfs(root,&res);
    return res;
}

int dfs(struct TreeNode* root,int *res){
    if(root==NULL) return 0;

    int lf = dfs(root->left,res);
    int rg = dfs(root->right,res);

    *res += abs(lf-rg);

    return lf + rg + root->val;
}
// @lc code=end

