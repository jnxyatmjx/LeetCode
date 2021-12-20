/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
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

    bool isSymmetric(TreeNode* root) {
        
        deque<TreeNode*> q1,q2;
        q1.push_front(root);
        q2.push_front(root);

        while(!q1.empty() && !q2.empty())
        {
            TreeNode* node1 = q1.back();q1.pop_back();
            TreeNode* node2 = q2.back();q2.pop_back();

            if(node1==NULL && node2==NULL) continue;
            if(node1==NULL || node2==NULL) return false;
            if(node1->val != node2->val) return false;

            q1.push_front(node1->left);// left subtree's left node symmtric right subtree's right node
            q2.push_front(node2->right);

            q1.push_front(node1->right);// left subtree's right node symmtric right subtree's left node
            q2.push_front(node2->left);
        }

        return true;
    }

    
};
// @lc code=end

