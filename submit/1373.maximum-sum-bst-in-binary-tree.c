/*
 * @lc app=leetcode id=1373 lang=c
 *
 * [1373] Maximum Sum BST in Binary Tree
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
#define maxl(a,b)\
({ __typeof__ (a) a_ = (a);\
    __typeof__ (b) b_ = (b);\
    a_ > b_ ? a_ : b_;})

struct context
{
    bool isBST;
    int min; //minimum node of this tree(means this tree's minimum node)
    int max; //maximum node of this tree(means this tree's maximum node)
    int sum; //this tree's(if is a BST) sum of nodes
};

struct context dfs(struct TreeNode* root,int *maxsum)
{
    ////make sure a leaf is BST
    //this is a NULL pseudo-node,make sure its parent node(a leaf node) process condition
    // --> root->val > left.max && root->val < right.min
    if(root == NULL)
    {
        struct context temp = {true,40001,-40001,0};
        return temp;
    }

    struct context left = dfs(root->left,maxsum);
    struct context right = dfs(root->right,maxsum);

    if(left.isBST==false || right.isBST==false ||
        root->val <= left.max || root->val >= right.min)
        /*root->val > left.max and root->val < right.min is BST*/
    {
        struct context temp = {false,0,0,0};
        return temp;
    }

    struct context temp;
    temp.isBST = true;
    temp.min = (root->left ? left.min : root->val);   //if has left subtree, set left subtre's min as total tree's minimum val
    temp.max = (root->right ? right.max : root->val); //if has right subtree, set right subtree's max as total tree's maximum val
    temp.sum = root->val + left.sum + right.sum;
    *maxsum = maxl(*maxsum,temp.sum);

    return temp;
}
//[4,3,null,1,2]
int maxSumBST(struct TreeNode* root){
    
    // Must initial a values or will get a wrong value
    // Example 3,All values are negatives. Return an empty BST.
    int maxSUm = 0;
    dfs(root,&maxSUm);
    
    return maxSUm;
}
// @lc code=end

