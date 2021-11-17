/*
 * @lc app=leetcode id=113 lang=cpp
 *
 * [113] Path Sum II
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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        vector<vector<int>> res;
        vector<int> path;
        helper( root,targetSum,path,res);
        return res;
    }
/*

[5,4,8,11,null,13,4,7,2,null,null,5,1]\n22

*/
    void helper(TreeNode* root,int targetSum,vector<int>& path,vector<vector<int>>& res)
    {
        if(root == NULL) return;
        
        path.push_back(root->val);
        
        if(root->left==NULL && root->right==NULL && targetSum==root->val)
        {
            res.push_back(path);
            path.pop_back();
            return; //reach leaf , just return
        }
        helper(root->left,targetSum - root->val,path,res);
        helper(root->right,targetSum - root->val,path,res);

        path.pop_back();
        
        return ;
    }
};
// @lc code=end

