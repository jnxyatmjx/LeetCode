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

        return help(root,NULL,NULL);
        // vector<int> res;

        // //BST inorder traverl is sorted vector
        // inorder_traver(root,res);
        
        // return is_sorted(res.begin(),res.end(), less_equal<int>());
    }

    void inorder_traver(struct TreeNode* root,vector<int>& res)
    {
        if(root==NULL) return;
        inorder_traver(root->left,res);
        res.push_back(root->val);
        inorder_traver(root->right,res);
    }

    /*
        lmax : left subtree of root's maximum node value
        rmin : right subtree of root's minimum node value
    */
    bool help(TreeNode* root,TreeNode* lmax,TreeNode* rmin)
    {
        if(root==NULL) return true;
        if(lmax && lmax->val >= root->val) return false;
        if(rmin && rmin->val <= root->val) return false;
        return help(root->left,lmax,root) && help(root->right,root,rmin);
    }
};
// @lc code=end

