/*
 * @lc app=leetcode id=101 lang=c
 *
 * [101] Symmetric Tree
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

bool ishelp(struct TreeNode* lft,struct TreeNode* rgt){

    if(lft==false && rgt==false )
        return true;

    if(lft==false || rgt==false)
        return false;

    if(lft->val != rgt->val)
        return false;


    return (lft->val == rgt->val ) &&
            ishelp(lft->left,rgt->right) && //left subtree's left node symmtric right subtree's right node
            ishelp(lft->right,rgt->left); //left subtree's right node symmtric right subtree's left node
}

bool isSymmetric(struct TreeNode* root)
{
    return ishelp(root,root);
}
// @lc code=end

