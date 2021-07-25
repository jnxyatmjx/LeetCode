/*
 * @lc app=leetcode id=145 lang=c
 *
 * [145] Binary Tree Postorder Traversal
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
({__typeof__ (a) a_ = (a);\
    __typeof__ (b) b_ = (b);\
    a_ > b_ ? a_: b_})

int nodeSize(struct TreeNode* root)
{
    if(root == NULL) return 0;
    int ls = nodeSize(root->left);
    int lr = nodeSize(root->right);
    return 1 + ls + lr;
}

void postorderHe(struct TreeNode* root,int* res,int* idx)
{
    if(root == NULL) return ;

    postorderHe(root->left,res,idx);
    postorderHe(root->right,res,idx);
    res[(*idx)++] = root->val;
}

int* postorderTraversal(struct TreeNode* root, int* returnSize){
    if(root == NULL)
    {
        *returnSize = 0;
        return NULL;
    }

    int noss = nodeSize(root);

    *returnSize = 0;
    int* res = (int*)calloc(noss,sizeof(int));

    postorderHe(root,res,returnSize);

    return res;
}
// @lc code=end

