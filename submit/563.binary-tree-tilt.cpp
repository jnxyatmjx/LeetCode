/*
 * @lc app=leetcode id=563 lang=cpp
 *
 * [563] Binary Tree Tilt
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
    Solution():res(0){}
    int findTilt(TreeNode* root) {
        dfs(root,&res);
        return res;
    }

    int dfs(TreeNode* root,int* res){
        if(root==NULL) return 0;

        int lf = dfs(root->left,res);
        int rg = dfs(root->right,res);
        (*res) += std::abs(lf-rg);
        return lf + rg + root->val;
    }
private:
    int res;
};
// @lc code=end

