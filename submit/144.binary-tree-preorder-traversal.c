/*
 * @lc app=leetcode id=144 lang=c
 *
 * [144] Binary Tree Preorder Traversal
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

void preorderHe(struct TreeNode* root,int* res,int* idx)
{
    if(root == NULL) return ;

    res[(*idx)++] = root->val;

    preorderHe(root->left,res,idx);

    preorderHe(root->right,res,idx);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize){
    if(root == NULL)
    {
        *returnSize = 0;
        return NULL;
    }

    *returnSize = 0;
    int nos = nodeSize(root);
    int* res = (int*)calloc(nos,sizeof(int));
    
    preorderHe(root,res,returnSize);

    return res;
}
// @lc code=end

