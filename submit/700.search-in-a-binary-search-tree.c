/*
 * @lc app=leetcode id=700 lang=c
 *
 * [700] Search in a Binary Search Tree
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
//iterator
struct TreeNode* searchBST(struct TreeNode* root, int val){
    if(root == NULL) return NULL;
    
    while(root)
    {
        if(root->val == val)
            return root;
        else if(root->val > val)
            root = root->left;
        else
            root = root->right;
    }
    return root;
}
/*
//recursive
struct TreeNode* searchBST(struct TreeNode* root, int val){
    if(root == NULL) return NULL;
    
    if(root->val == val)
        return root;
    else if(root->val > val)
        return searchBST(root->left,val);
    else
        return searchBST(root->right,val);
}
*/
// @lc code=end

