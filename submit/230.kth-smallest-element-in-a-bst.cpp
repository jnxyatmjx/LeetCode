/*
 * @lc app=leetcode id=230 lang=cpp
 *
 * [230] Kth Smallest Element in a BST
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
    //k from 1-index
    int kthSmallest(TreeNode* root, int k) {
        //use Divide and conquer
        int c = cout(root->left); //number of left subtree's nodes
        if(k-1 < c)
            return kthSmallest(root->left,k);
        else if(k-1 > c)
            return kthSmallest(root->right,k-c-1);//k-c-1[k - (c+1)] means minus left subtree's nodes

        return root->val;
    }

    int cout(TreeNode* root)
    {
        if(root==NULL) return 0;
        return 1 + cout(root->left) + cout(root->right);
    }

};
// @lc code=end

