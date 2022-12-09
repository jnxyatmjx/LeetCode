/*
 * @lc app=leetcode id=572 lang=c
 *
 * [572] Subtree of Another Tree
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

bool same(struct TreeNode* r1,struct TreeNode* r2){
    if(r1==NULL && r2==NULL)
        return true;
    
    if( (r1==NULL || r2==NULL) || (r1->val != r2->val) )
        return false;
    
    return same(r1->left,r2->left) && same(r1->right,r2->right);
}

bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot){
    
    //traverse all nodes in root,but not find the same value with subRoot
    // root move , subRoot not move
    if(root==NULL/* && subRoot==NULL */) return false;

    
    if(same(root,subRoot)) return true;

    return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
}
// @lc code=end

