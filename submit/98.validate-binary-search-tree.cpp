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
        vector<int> res;

        //BST inorder traverl is sorted vector
        inorder_traver(root,res);
        
        return is_sorted(res.begin(),res.end(), less_equal<int>());
    }

    void inorder_traver(struct TreeNode* root,vector<int>& res)
    {
        if(root==NULL) return;
        inorder_traver(root->left,res);
        res.push_back(root->val);
        inorder_traver(root->right,res);
    }
};
// @lc code=end

