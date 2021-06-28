/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
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
    vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> res;
        std::deque<TreeNode*> st;//use as Stack
        while( root || !st.empty())
        {
            if(root)
            {
                st.push_back(root);
                root = root->left;
            }
            else
            {
                root = st.back(); st.pop_back();
                res.push_back(root->val);
                root = root->right;
            }
        }
        
        return std::move(res);
    }
};
// @lc code=end

