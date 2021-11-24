/*
 * @lc app=leetcode id=99 lang=c
 *
 * [99] Recover Binary Search Tree
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

int nodeNums(struct TreeNode* root)
{
    if(root == NULL) return 0;
    int ls = nodeNums(root->left);
    int lr = nodeNums(root->right);
    return 1 + ls + lr;
}

void inordeHelp(struct TreeNode* root,int* vals,struct TreeNode** lists,int* idx)
{
    if(root == NULL) return;

    inordeHelp(root->left,vals,lists,idx);

    vals[*idx] = root->val;
    lists[*idx] = root;
    (*idx)++;

    inordeHelp(root->right,vals,lists,idx);
}

int comap(const void* a,const void* b)
{
    return *(const int*)(a) >= *(const int*)(b);
}

void recoverTree(struct TreeNode* root){
    
    int nodexs = nodeNums(root);
    
    int* vals = (int *)calloc(nodexs,sizeof(int));
    struct TreeNode** lists = (struct TreeNode**)calloc(nodexs,sizeof(struct TreeNode*));
    int* idx = (int*)calloc(1,sizeof(int));
    *idx = 0;

    inordeHelp(root,vals,lists,idx);
    qsort(vals,nodexs,sizeof(int),comap);

    for(int i=0; i<nodexs; i++)
    {
        lists[i]->val = vals[i];
    }

    free(vals);
    free(lists);
    free(idx);
}
// @lc code=end

