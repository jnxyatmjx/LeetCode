/*
 * @lc app=leetcode id=111 lang=cpp
 *
 * [111] Minimum Depth of Binary Tree
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
//[2,null,3,null,4,null,5,null,6,89]\n
//[3,9,20,null,null,15,7]\n
    int minDepth(TreeNode* root) {
        if(root==NULL) return 0;

        int left = minDepth(root->left);
        int righ = minDepth(root->right);

        if(left == 0) return righ + 1; //when recursive back, save the usefull value
        if(righ == 0) return left + 1; //when recursive back, save the usefull value

        return 1 + min(left,righ);
    }

};
// @lc code=end

