/*
 * @lc app=leetcode id=95 lang=cpp
 *
 * [95] Unique Binary Search Trees II
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
//https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247490696&idx=1&sn=798a350fcca16c89572caf65323dbec7&scene=21#wechat_redirect

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
       
       return build(1,n);

    }

    vector<TreeNode*> build(int lft, int rgt)
    {
        if(lft>rgt) return {NULL};//for NULL node

        vector<TreeNode*> res;

        for(int i=lft; i<=rgt; i++)
        {
            vector<TreeNode*> left  = build(lft,i-1);
            vector<TreeNode*> right = build(i+1,rgt);

            for(auto l:left)
                for(auto r:right)
                {
                    TreeNode* root = new TreeNode(i);//i as root node of subtree
                    root->left = l;
                    root->right = r;
                    res.push_back(root);
                }
        }

        return move(res);//like post order traversal
    }
};
// @lc code=end

