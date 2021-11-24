/*
 * @lc app=leetcode id=98 lang=c
 *
 * [98] Validate Binary Search Tree
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
/*
bool preorder_traver(struct TreeNode* root,struct TreeNode* min,struct TreeNode* max)
{
    if(root==NULL) return true;

    if(min!=NULL && root->val <= min->val) return false;
    if(max!=NULL && root->val >= max->val) return false;
    
    return preorder_traver(root->left,min,root) && preorder_traver(root->right,root,max);
}

bool isValidBST(struct TreeNode* root){

    return preorder_traver(root,NULL,NULL);
}
*/

bool isValidBST(struct TreeNode* root){
    
    //variables must be a global for c language
    struct TreeNode** pre = (struct TreeNode*)calloc(1,sizeof(struct TreeNode*));
    bool isValid = true;

    inorder_traver(root,pre,&isValid);
    
    return isValid;
}

void inorder_traver(struct TreeNode* root,struct TreeNode **pre,bool *valid)
{
    if(root == NULL) return;
    
    inorder_traver(root->left,pre,valid);

    //BST inorder traversal have line increase
    if( *pre )
    {
        if( (*pre)->val >= root->val)
            *valid = false;
    }
    *pre = root;

    inorder_traver(root->right,pre,valid);
}

// @lc code=end

