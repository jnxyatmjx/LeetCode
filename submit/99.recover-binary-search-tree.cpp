/*
 * @lc app=leetcode id=99 lang=cpp
 *
 * [99] Recover Binary Search Tree
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
    void recoverTreeHelper(TreeNode *root) {
        
        if (root == NULL) return;
        
        recoverTreeHelper(root->left);
        if (prev) {
            if (prev->val > root->val){
                if (n1==NULL) {
                    n1 = prev;
                }
                n2 = root;
            }
        }
        prev = root;
        recoverTreeHelper(root->right);
    }
    
    void recoverTree(TreeNode *root) {
        n1 = n2 = prev = NULL;
        recoverTreeHelper(root);
        if (n1 && n2) {
            swap(n1->val, n2->val);
        }
    }
private:
    TreeNode *n1, *n2, *prev;
};
// @lc code=end

