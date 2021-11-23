/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        
        return preorder_traver(root,NULL,NULL);
    }

    bool preorder_traver(struct TreeNode* root,struct TreeNode* min,struct TreeNode* max)
    {
        if(root==NULL) return true;

        if(min!=NULL && root->val <= min->val) return false;
        if(max!=NULL && root->val >= max->val) return false;

        return preorder_traver(root->left,min,root) && preorder_traver(root->right,root,max);
    }
};
// @lc code=end

