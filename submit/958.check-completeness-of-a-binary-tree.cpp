/*
 * @lc app=leetcode id=958 lang=cpp
 *
 * [958] Check Completeness of a Binary Tree
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
    bool isCompleteTree(TreeNode* root) {
        if(root==NULL) return true;
        std::deque<TreeNode*> q;
        q.push_back(root);
        while (q.front() != nullptr)//if find first null then stop
        {
           TreeNode* cur = q.front(); q.pop_front();
           q.push_back(cur->left);
           q.push_back(cur->right);
        }
        //after first null ,if you find a value this mean not a complete tree
        while(!q.empty() && q.front()==NULL)
            q.pop_front();
        
        return q.empty();
    }
};
// @lc code=end

