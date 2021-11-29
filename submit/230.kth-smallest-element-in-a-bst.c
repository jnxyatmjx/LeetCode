/*
 * @lc app=leetcode id=230 lang=c
 *
 * [230] Kth Smallest Element in a BST
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
//inorder traversal have a line increase array

void inorder_trav(struct TreeNode* root,int k,int* idx,int* res)
{
    if(root == NULL) return;
    inorder_trav(root->left,k,idx,res);
    if(*idx == k) *res = root->val;
    *idx += 1;
    inorder_trav(root->right,k,idx,res);
}

int kthSmallest(struct TreeNode* root, int k){
    if(root==NULL) return -1;

    int res ,idx = 1;
    inorder_trav(root,k,&idx,&res);
    return res;
}
// @lc code=end

