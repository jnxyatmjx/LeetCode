/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
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

    void dfs(std::vector<std::vector<int>>& res,int level,TreeNode* root)
    {
        if(root == NULL) return;

        if(res.size() <= level)
            res.push_back(std::vector<int>(0));
        
        res[level].push_back(root->val);

        dfs(res,level+1,root->left);
        dfs(res,level+1,root->right);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {

        std::vector<std::vector<int> > res;
        if(root == NULL) return std::move(res);

        dfs(res,0,root);

        return std::move(res);
/*
        std::deque<TreeNode*> lis_;lis_.push_front(root);
        while( !lis_.empty() )
        {
            std::vector<int> res_temp;
            for(int i=lis_.size(); i>0; i--)
            {
                TreeNode* tmp = lis_.back(); lis_.pop_back();
                if(tmp->left)
                    lis_.push_front(tmp->left);

                if(tmp->right)
                    lis_.push_front(tmp->right);

                res_temp.push_back(tmp->val);
            }//end one level

            res.push_back(std::move(res_temp));
        }
        return std::move(res);
*/
    }
};
// @lc code=end

