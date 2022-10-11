/*
 * @lc app=leetcode id=111 lang=cpp
 *
 * [111] Minimum Depth of Binary Tree
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
//[2,null,3,null,4,null,5,null,6,89]\n
//[3,9,20,null,null,15,7]\n
    int minDepth1(TreeNode* root) {
        if(root==NULL) return 0;

        int left = minDepth(root->left);
        int righ = minDepth(root->right);

        if(left == 0) return righ + 1; //when recursive back, save the usefull value
        if(righ == 0) return left + 1; //when recursive back, save the usefull value

        return 1 + min(left,righ);
    }

    int minDepth(TreeNode* root) {
       if (root==NULL) return 0;
       int res=0;
       std::deque<TreeNode*> que_;
       que_.push_back(root);
       while (que_.size() > 0)
       {
            res++;//new level
            for(size_t i=que_.size(); i>0; i--){
                TreeNode* cur = que_.front();que_.pop_front();
                if(cur->left==NULL && cur->right==NULL) return res; //this level's leaf node
                if(cur->left)  que_.push_back(cur->left);
                if(cur->right) que_.push_back(cur->right);
            }//end for
       }//end while
       return -1;
    }
};
// @lc code=end

