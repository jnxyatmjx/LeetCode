/*
 * @lc app=leetcode id=94 lang=c
 *
 * [94] Binary Tree Inorder Traversal
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


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define maxl(a,b)\
({ __typeof__ (a) a_ = (a);\
    __typeof__ (b) b_ = (b);\
    a_ > b_ ? a_:b_;})

int getNodes(struct TreeNode* root)
{
    if(root == NULL) return 0;

    int ls = getNodes(root->left);
    int rs = getNodes(root->right);
    return 1 + ls + rs;
}

void inorderHe(struct TreeNode* root,int *res,int *idx)
{
    if(root == NULL) return ;
    inorderHe(root->left,res,idx);
    res[(*idx)++] = root->val;
    inorderHe(root->right,res,idx);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize){

    if(root == NULL)
    {
        *returnSize = 0;
        return NULL;
    }

    int snodes = getNodes(root);
  
    int* res = (int*)calloc(snodes,sizeof(int));
    *returnSize = 0;

    inorderHe(root,res,returnSize);
    return res;
}
// @lc code=end

