/*
 * @lc app=leetcode id=1373 lang=cpp
 *
 * [1373] Maximum Sum BST in Binary Tree
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

int maxsum = 0;
public:
    int maxSumBST(TreeNode* root) {
        dfs(root);
        return maxsum;
    }
    //vector<int> --> this root isBST, 
    //                minimum node of root's left subtree, 
    //                maximum node of root's right subtree, 
    //                sum

    //vector[1] --> root's minimum node if is BST
    //vector[2] --> root's maximum node if is BST

    vector<int> dfs(TreeNode* root) {
        if (!root) return {true, INT_MAX, INT_MIN, 0};

        auto lft = dfs(root->left);
        auto rgt = dfs(root->right);

        int sum , curmax, curmin;
        if (!lft[0] || !rgt[0] 
            || root->val >= rgt[1]/*root greater than right subtree's minimum val*/ 
            || root->val <= lft[2]/*root less than left subtree's maximum val*/) {
            return {false, 0, 0, 0};
        }

        curmin = root->left ? lft[1] : root->val;
        curmax = root->right ? rgt[2] : root->val;
        sum = (root->val + lft[3] + rgt[3]);
        maxsum = max(maxsum, sum);
        return {true, curmin, curmax, sum};
    }
};
// @lc code=end

