/*
 * @lc app=leetcode id=450 lang=c
 *
 * [450] Delete Node in a BST
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
//[5,3,6,2,4,null,7]\n7\n leaf
//[5,3,6,2,4,null,7]\n6\n one child
//[5,3,6,2,4,null,7]\n3\n two childrens
void delNode(struct TreeNode* node)
{
    if(node == NULL) return ;
    free(node);
    node = NULL;
}

struct TreeNode* findMin(struct TreeNode* root)
{
    if(root == NULL) return NULL;
    while (root->left)
    {
        root = root->left;
    }
    return root;
}

struct TreeNode* deleteNode(struct TreeNode* root, int key){
    if(root==NULL) return NULL;

    if(root->val == key)
    {
        //node have two childrens
        if(root->left && root->right)
        {
            struct TreeNode* currT = findMin(root->right);
            root->val = currT->val;
            root->right = deleteNode(root->right,/**/currT->val);
            
        }else {
            struct TreeNode* cruT = root;
            if(cruT->left == NULL)
                root = cruT->right;
            
            if(cruT->right == NULL)
                root = cruT->left;
            
            delNode(cruT);
        }

    }else if(root->val > key)
        root->left = deleteNode(root->left,key);
    else
        root->right = deleteNode(root->right,key);

    return root;
    
}
// @lc code=end

