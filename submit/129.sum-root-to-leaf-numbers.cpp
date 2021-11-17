/*
 * @lc app=leetcode id=129 lang=cpp
 *
 * [129] Sum Root to Leaf Numbers
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
    int sumNumbers(TreeNode* root) {
        int res = 0;
        int pathsum = 0;
        helper(root,&pathsum,&res);
        return res;
    }

    void helper(TreeNode* root,int* pathsum,int *res)
    {
        if(root==NULL) return ;

        *pathsum = (*pathsum) * 10 + root->val;

        if(root->left==NULL && root->right==NULL)
        {
            *res += *pathsum;
            *pathsum = (*pathsum - root->val)/10;
            return ;
        }
        
        helper(root->left,pathsum,res);
        helper(root->right,pathsum,res);

        *pathsum = (*pathsum - root->val)/10;
    }
};
// @lc code=end

