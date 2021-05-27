/*
 * @lc app=leetcode id=144 lang=cpp
 *
 * [144] Binary Tree Preorder Traversal
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
    vector<int> preorderTraversal(TreeNode* root) {
        std::vector<int> res;
        std::deque<TreeNode*> stk;
        while(root || !stk.empty())
        {
            if(root)
            {
                res.push_back(root->val);
                if(root->right) stk.push_back(root->right);
                root = root->left;
            }else
            {
                root = stk.back();stk.pop_back();
            }
        }

        return std::move(res);
    }
};
// @lc code=end

