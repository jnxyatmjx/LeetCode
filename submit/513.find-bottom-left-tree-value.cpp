/*
 * @lc app=leetcode id=513 lang=cpp
 *
 * [513] Find Bottom Left Tree Value
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
    int findBottomLeftValue(TreeNode* root) {
        int res;
        std::deque<TreeNode*> q;
        q.push_back(root);
        while(!q.empty()){
            std::size_t n = q.size();
            for(std::size_t i=0; i<n; i++){
                root = q.front(); q.pop_front();
                if(i==0) res = root->val;
                if(root->left) q.push_back(root->left);
                if(root->right) q.push_back(root->right);
            }
        } //end while
        return res;
    }
};
// @lc code=end

