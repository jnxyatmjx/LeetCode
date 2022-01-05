/*
 * @lc app=leetcode id=653 lang=cpp
 *
 * [653] Two Sum IV - Input is a BST
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

    //use hashset to find the special value
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL) return false;
        set<int> keys;
        return pre_ord(root,k,keys);
    }

    bool pre_ord(TreeNode* root,int k,set<int>& keys)
    {
        if(root==NULL) return false;

        if(keys.count(k-root->val) > 0) return true;
        keys.insert(root->val);

        return pre_ord(root->left,k,keys) ||
            pre_ord(root->right,k,keys);
    }

    // use a sort array find sum of k
    bool findTarget1(TreeNode* root, int k) {
        vector<int> res;
        in_order(root,res);
        
        return find_sum_k(res,0,res.size()-1,k);
    }

    void in_order(TreeNode* root,vector<int>& res)
    {
        if(root==NULL) return ;
        in_order(root->left,res);
        res.push_back(root->val);
        in_order(root->right,res);
    }

    bool find_sum_k(vector<int>& res,int l,int r,int k)
    {
       while( l < r) //l<=r [1]\n2 is error
       {
           if(k - res[l] == res[r]) // plus maybe overflow?
                return true;
            else if(k - res[l] > res[r])
                l++;
            else if(k - res[l] < res[r])
                r--;
       }
        return false;
    }
};
// @lc code=end

