/*
 * @lc app=leetcode id=129 lang=c
 *
 * [129] Sum Root to Leaf Numbers
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

int sumHelper(struct TreeNode* root,int parentVal)
{
    if(root == NULL) return 0;

    //if root is a leaf node
    if(root->left==NULL && root->right==NULL)
        return 10*parentVal + root->val;

    //process left and right subtree
    int sum = 0;
    sum += sumHelper(root->left,10*parentVal + root->val);
    sum += sumHelper(root->right,10*parentVal + root->val);
    return sum;
}

int sumNumbers(struct TreeNode* root){
    if(root == NULL) return 0;
    
    return sumHelper(root,0);
}
// @lc code=end

