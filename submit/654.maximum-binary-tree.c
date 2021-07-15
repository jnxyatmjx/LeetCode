/*
 * @lc app=leetcode id=654 lang=c
 *
 * [654] Maximum Binary Tree
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

struct TreeNode * createNode(int val)
{
    struct TreeNode * nd = (struct TreeNode *)calloc(1,sizeof(struct TreeNode));
    nd->val = val;
    return nd;
}

struct TreeNode * constructHelper(int* nums,int lf,int rg)
{
    if (lf > rg) return NULL;

    //find maximum value and index in the sub array
    int maxv = nums[lf],idx = lf;
    for(int i=lf+1; i<=rg; i++)
        if(maxv < nums[i])
        {
            maxv = nums[i];
            idx = i;
        }

    struct TreeNode * root = createNode(maxv);
    
    //process left and right node
    root->left = constructHelper(nums,lf,idx-1);
    root->right = constructHelper(nums,idx+1,rg);
    
    return root;
}

struct TreeNode* constructMaximumBinaryTree(int* nums, int numsSize)
{
    return constructHelper(nums,0,numsSize-1);
}
// @lc code=end

