/*
 * @lc app=leetcode id=108 lang=c
 *
 * [108] Convert Sorted Array to Binary Search Tree
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
struct TreeNode* createNode(int val)
{
    struct TreeNode* temp = (struct TreeNode*)calloc(1,sizeof(struct TreeNode));
    temp->val = val;
    return temp;
}

struct TreeNode* bstHe(int* nums ,int lef,int rig)
{
    if(lef > rig) return NULL;
    int mid = lef + (rig-lef)/2;
    struct TreeNode* root = createNode(nums[mid]);
    root->left = bstHe(nums,lef,mid-1);
    root->right = bstHe(nums,mid+1,rig);
    return root;
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize){
    if(numsSize==0 || nums==NULL) return NULL;

    return bstHe(nums,0,numsSize-1); // the result is not UNIQUE
}
// @lc code=end

