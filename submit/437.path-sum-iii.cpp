/*
 * @lc app=leetcode id=437 lang=cpp
 *
 * [437] Path Sum III
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
#if 0
    int pathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;
        return sumUp(root, 0, targetSum) + pathSum(root->left, targetSum) + pathSum(root->right, targetSum);
    }

    int sumUp(TreeNode* root, int pre, int& targetSum){
        if(!root) return 0;
        int current = pre + root->val;
        return (current == targetSum) + sumUp(root->left, current, targetSum) + sumUp(root->right, current, targetSum);
    }
#endif

    int pathSum(TreeNode* root, int sum) {
        int res = 0;
        vector<TreeNode*> out;
        helper(root, sum, 0, out, res);
        return res;
    }
    void helper(TreeNode* node, int sum, int curSum, vector<TreeNode*>& out, int& res) {
        if (!node) return;
        curSum += node->val;
        out.push_back(node);
        if (curSum == sum) ++res;
        int t = curSum;
        for (int i = 0; i < out.size() - 1; ++i) {
            t -= out[i]->val;
            if (t == sum) ++res;
        }
        helper(node->left, sum, curSum, out, res);
        helper(node->right, sum, curSum, out, res);
        out.pop_back();
    }
};
// @lc code=end

