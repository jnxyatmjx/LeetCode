/*
 * @lc app=leetcode id=501 lang=cpp
 *
 * [501] Find Mode in Binary Search Tree
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
//[59,34,70,12,40,70,70]
//[59,34,70,34,40,null,70]
//[59,34,70,34,34,null,70]

private:
    int cout=0; // current value's number of occurrences
    int mxc=-1; // maximum occurrences of the special value
    int prev;

public:
    vector<int> findMode(TreeNode* root) {
        
        vector<int> res;
        help(root,res);
        return res;
    }

    void help(TreeNode* root,vector<int>& res)
    {
        if(root==NULL) return;


        help(root->left,res);
        
        //set occurrence
        if(cout == 0)//first find value in binary tree
        {
            prev = root->val;
            cout = 1;
        }else {
            if(prev == root->val)//find duplicate value in binary tree
            {
                cout++;
            }else{
                cout = 1;
                prev = root->val;
            }
        }

        //push res vector
        if(mxc < cout)
        {
            mxc = cout;
            res.clear();
            res.push_back(prev);
            
        }else if(mxc == cout){
            res.push_back(prev);
        }
        

        help(root->right,res);
    }
};
// @lc code=end

