/*
 * @lc app=leetcode id=145 lang=cpp
 *
 * [145] Binary Tree Postorder Traversal
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
    
    // reverse pseudo-preorder[root,right,left] --- {preorder[root,left,right]}
     vector<int> postorderTraversal(TreeNode* root)
     {
        if(root==NULL) return vector<int>(0);
        
        vector<int>res;
        deque<TreeNode*> q;
        while(!q.empty() || root)
        {
            if(root != NULL)
            {
                res.insert(res.begin(),root->val); //insert into header of vector
                if(root->left) q.push_back(root->left);
                root = root->right;
            }else
            {
                root = q.back();q.pop_back();
            }
        }
        return res;
     }

    //traditional method
    vector<int> postorderTraversal222(TreeNode* root) {
        std::vector<int> res;
        std::deque<TreeNode*> stk;//Use a Stack
        TreeNode* lastVisit = NULL; //the last node visited
        
        while(root || !stk.empty())
        {
            if(root)
            {
                stk.push_back(root);
                root = root->left;
            }
            else
            {
                TreeNode* stkTop = stk.back();
                if(stkTop->right != NULL && stkTop->right != lastVisit)
                {
                    root = stkTop->right;
                }
                else
                {
                    res.push_back(stkTop->val);
                    lastVisit = stk.back();stk.pop_back();
                    root = NULL;
                }

            }//end else
        }//end while

        return std::move(res);
    }
};
// @lc code=end

