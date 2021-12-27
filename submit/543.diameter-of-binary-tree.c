/*
 * @lc app=leetcode id=543 lang=c
 *
 * [543] Diameter of Binary Tree
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
    a_ > b_ ? a_ : b_; })

int help(struct TreeNode* root,int* res)
{
    if(root==NULL) return 0;
    
    // maximum depth length
    int left=help(root->left,res);
    int right=help(root->right,res);

    int maxd = maxl(left, right) + 1;//return maximum depth of this node
    *res = maxl(*res,left + right);

    return maxd;
}

//one node's longest diameter is it's sum of
// Left subtree and Right subtree 's 
//maximum depth
int diameterOfBinaryTree(struct TreeNode* root){
    if(root==NULL) return 0;
    
    int rs = 0;
    help(root,&rs);

    return rs;

}
// @lc code=end

