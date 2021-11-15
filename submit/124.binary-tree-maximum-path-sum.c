/*
 * @lc app=leetcode id=124 lang=c
 *
 * [124] Binary Tree Maximum Path Sum
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



int maxPathSum(struct TreeNode* root){
    int nmax = -1001;
    helper(root,&nmax);
    return nmax;
}

/*
    [-1,2,-3]\n

*/
int helper(struct TreeNode* root,int *nmax)
{
    if(root == NULL) return 0;
    int maxl = lmax(0,helper(root->left,nmax) );
    int maxr = lmax(0,helper(root->right,nmax) );
    *nmax = lmax(*nmax,maxl+maxr+root->val);
    
    return lmax(maxl,maxr) + root->val;
    //return maximum left or right subtree and root path sum
}

// @lc code=end

