/*
 * @lc app=leetcode id=701 lang=c
 *
 * [701] Insert into a Binary Search Tree
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
    1-->first:  inorder traver into a vector
       second:  insert val into associate position of this vector
        third:  rebuilt the tree
    BUT this solution is more space 

    2--> like serach node in BST
*/
/*
int numBST(struct TreeNode* root)
{
    if(root == NULL) return 0;
    return 1 + numBST(root->left) + numBST(root->right);
}
void inorder_bst(struct TreeNode* root,int* res,int* idx)
{
    if(root == NULL) return;
    inorder_bst(root->left,res,idx);
    res[(*idx)++] = root->val;
    inorder_bst(root->right,res,idx);
}

struct TreeNode* insertIntoBST(struct TreeNode* root, int val){
    int resnum = numBST(root) + 1;
    int * res = (int*)calloc(resnum,sizeof(int));
    int idx = 0;
    inorder_bst(root,res,&idx);

    for(int i=0; i<resnum; i++)
        printf("%d ",res[i]);
    printf("\n");
    return NULL;
}
*/

struct TreeNode* createNode(int val)
{
    struct TreeNode* root = (struct TreeNode*)calloc(1,sizeof(struct TreeNode));
    root->val = val;
    return root;
}
struct TreeNode* insertIntoBST(struct TreeNode* root, int val){
    
    if(root==NULL) 
        return createNode(val);
    
    if(root->val > val)
        root->left = insertIntoBST(root->left,val);
    else
        root->right = insertIntoBST(root->right,val);
    
    return root;
}

// @lc code=end

