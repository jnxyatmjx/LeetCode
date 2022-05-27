/*
 * @lc app=leetcode id=1302 lang=cpp
 *
 * [1302] Deepest Leaves Sum
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
//[6,7,8,2,7,null,null,9,null,1,4,null,null,null,5]\n
    int deepestLeavesSum(TreeNode* root) {
        
        //Level traversal
        std::deque<TreeNode*> que_;
        que_.push_front(root);
        int res = 0;
        while( !que_.empty() ){
            res = 0;
            for(size_t i=que_.size(); i>0; i--)
            {
                TreeNode* tmp = que_.back(); que_.pop_back();
                res += tmp->val;
                if(tmp->left) que_.push_front(tmp->left);
                if(tmp->right) que_.push_front(tmp->right);
            }
            //end 1 level traversal
        }
        return res;
    }
};
// @lc code=end

