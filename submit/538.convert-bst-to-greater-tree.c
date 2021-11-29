/*
 * @lc app=leetcode id=538 lang=c
 *
 * [538] Convert BST to Greater Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


//same to 1038

//BST .recursive -> left root right make a increase array
//BST .recursive -> right root left make a decrease array
void inorder_tr(struct TreeNode* root ,int *sum)
{
    if(root == NULL) return;
    inorder_tr(root->right,sum); // from right subtree
    
    *sum += root->val;
    root->val = *sum;
    
    inorder_tr(root->left,sum); // to left subtree
}

struct TreeNode* convertBST(struct TreeNode* root){
    
    int sum = 0;
    inorder_tr(root,&sum);
    return root;
}
// @lc code=end

