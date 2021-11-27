/*
 * @lc app=leetcode id=450 lang=cpp
 *
 * [450] Delete Node in a BST
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
    void delNode(TreeNode* root)
    {
        if(root == NULL) return;
        delete root;root = NULL;
    }

    TreeNode* findMin(TreeNode* root)
    {
        if(root == NULL) return NULL;

        while(root->left)
            root = root->left;
        
        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return NULL;

        if(root->val == key)
        {
            //double leaves at this root
            if(root->left && root->right)
            {
                TreeNode* cur = findMin(root->right); //find minimum node of right subtree
                root->val = cur->val;
                root->right = deleteNode(root->right,root->val);

            }else // one or none leaf at this root
            {
                struct TreeNode* cur = root;
                if(cur->left == NULL)
                    root = cur->right;
                
                if(cur->right == NULL)
                    root = cur->left;

                delNode(cur); //recursive process can insert into the original tree
            }
        }else if(root->val > key)
        {
            root->left = deleteNode(root->left,key);
        }else{
            root->right = deleteNode(root->right,key);
        }
        return root;
    }
};
// @lc code=end

