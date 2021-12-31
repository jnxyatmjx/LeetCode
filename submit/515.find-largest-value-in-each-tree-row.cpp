/*
 * @lc app=leetcode id=515 lang=cpp
 *
 * [515] Find Largest Value in Each Tree Row
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
#define maxl(a,b)\
({ __typeof__ (a) a_ = (a);\
 __typeof__ (b) b_ = (b);\
 a_ > b_ ? a_ :b_;})

class Solution {
public:
    vector<int> largestValues1(TreeNode* root) {
        if(root==NULL) return {};

        vector<int> res;

        deque<TreeNode*> que;
        que.push_front(root);

        while(!que.empty())
        {
            int max = INT_MIN;
            for(int i=que.size(); i>0; i--)
            {
                TreeNode* cur = que.back();que.pop_back();
                if(max < cur->val) max = cur->val;

                if(cur->left) que.push_front(cur->left);
                if(cur->right) que.push_front(cur->right);

            }//end one level of tree

            res.push_back(max);
        }//end while

        return res;
    }

    vector<int> largestValues(TreeNode* root)
    {
        vector<int> res;
        help(root,res,0);

        return res;
    }

    void help(TreeNode* root,vector<int>& res,int level)
    {
        if(root==NULL) return ;

        //use recursive (pre-order) traversal to simulation (iterator) level traversal
        if(res.size() == level)
            res.push_back(root->val); //insert the first value for this level
        else{
            res[level] = maxl(res[level],root->val); //update the real max value
        }

        help(root->left,res,level+1);
        help(root->right,res,level+1);
    }
};
// @lc code=end

