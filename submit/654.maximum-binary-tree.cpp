/*
 * @lc app=leetcode id=654 lang=cpp
 *
 * [654] Maximum Binary Tree
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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        TreeNode * root = helper(nums,0,static_cast<int>(nums.size())-1);
        return root;
    }

    TreeNode* helper(vector<int>& nums,int lft,int rgt)
    {
        if(lft > rgt) return NULL;
        
        int maxv=nums[lft], idx=lft;
        for (int i=lft; i<=rgt; i++)
        {
            if(nums[i] > maxv)
            {
                maxv = nums[i];
                idx = i;
            }
        }

        TreeNode * root = new TreeNode(maxv);
        root->left = helper(nums,lft,idx-1);
        root->right = helper(nums,idx+1,rgt);

        return root;
    }
};
// @lc code=end

