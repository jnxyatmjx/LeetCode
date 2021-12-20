/*
 * @lc app=leetcode id=107 lang=cpp
 *
 * [107] Binary Tree Level Order Traversal II
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root == NULL) return {};
        
        deque<TreeNode*> q;
        q.push_front(root);

        vector<vector<int>> res;
        while(!q.empty())
        {
            vector<int> te_res;
            for(size_t i=q.size(); i>0; i--)
            {
                TreeNode* root = q.back();q.pop_back();
                te_res.push_back(root->val);

                if(root->left) q.push_front(root->left);
                if(root->right) q.push_front(root->right);
            }

            res.insert(res.begin(),te_res);
        }

        return res;
    }
};
// @lc code=end

