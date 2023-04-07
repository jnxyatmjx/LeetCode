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
    [2,-1]\n

*/
int helper(struct TreeNode* root,int *nmax)
{
    if(root == NULL) return 0;
    
    int maxl = helper(root->left,nmax);
    int maxr = helper(root->right,nmax);

    //return only one branch (maximum left or right subtree) plus root path sum
    //when left or right subtree node is negative,discard negative value
    int curmax = lmax((lmax(maxl,maxr) + root->val),root->val); //discard negative value

    //update maximum result
    *nmax = lmax(*nmax,lmax(curmax,maxl + maxr + root->val) );
    
    return curmax; //this node as root and the maximum sum path of subtree
}

// int helper(struct TreeNode* root,int *nmax)
// {
//     if(root == NULL) return 0;
//     int maxl = lmax(0,helper(root->left,nmax) ); //discard the negative value
//     int maxr = lmax(0,helper(root->right,nmax) );
//     *nmax = lmax(*nmax,maxl+maxr+root->val);

//     return lmax(maxl,maxr) + root->val;
//     //return maximum left or right subtree and root path sum
// }

// @lc code=end

