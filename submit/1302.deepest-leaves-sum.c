/*
 * @lc app=leetcode id=1302 lang=c
 *
 * [1302] Deepest Leaves Sum
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

#define lmax(a,b) \
({ __typeof__ (a) a_ = (a); \
   __typeof__ (b) b_ = (b); \
   a_ > b_ ? a_ : b_;\
})

#define lmin(a,b)\
({__typeof__ (a) a_ = (a);\
  __typeof__ (b) b_ = (b);\
   a_ < b_ ? a_ : b_;})
//[1,2,3,4,5,null,6,7,null,null,null,null,8]\n
//[6,7,8,2,7,null,null,9,null,1,4,null,null,null,5]\n
int deepestLeavesSum(struct TreeNode* root){
    
    if(root==NULL) return 0;

    int maxlev = 0, res = 0;
    dfs(root,0,&maxlev,&res);

    return res;
}

void dfs(struct TreeNode* root, int lev, int* maxlev, int* res)
{
    if(root==NULL) 
        return;

    if(lev > *maxlev){ //reset res and maxlev for the new deeper level nodes
        *maxlev = lev;
        *res = 0;
    }

    if(lev == *maxlev){
        *res += root->val; //add node sum for the maximum level
    }

    dfs(root->left,lev+1,maxlev,res);
    dfs(root->right,lev+1,maxlev,res);
}
// @lc code=end

