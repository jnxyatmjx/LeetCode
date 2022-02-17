/*
 * @lc app=leetcode id=606 lang=cpp
 *
 * [606] Construct String from Binary Tree
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
    string tree2str(TreeNode* root) {
        
        std::string res;
        pre_ord(root,res);
        printf("%s\n",res.c_str());
        return std::string(res.begin()+1,res.end()-1);
    }
//[1,2,null,3,4]
//[1,2,3,4]
    void pre_ord(TreeNode* root,std::string& res)
    {
        if(root==NULL)
        {
            //res += "()";
            return ;
        }
        
        res += "(" + std::to_string(root->val);
        if (root->left==NULL && root->right) res += "()";
        pre_ord(root->left,res);
        pre_ord(root->right,res);
        res += ")";
    }
};
// @lc code=end

