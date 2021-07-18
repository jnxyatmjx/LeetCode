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
int idx = 0;

int nodeNums(struct TreeNode* root)
{
    if(root == NULL) return 0;
    return 1 + nodeNums(root->left) + nodeNums(root->right);
}

void inordeHelp(struct TreeNode* root,int* vals,struct TreeNode** lists)
{
    if(!root) return;

    inordeHelp(root->left,vals,lists);

    vals[idx] = root->val;
    lists[idx] = root;
    idx++;

    inordeHelp(root->right,vals,lists);
}

int comap(const void* a,const void* b)
{
    return *(const int*)(a) >= *(const int*)(b);
}
void recoverTree(struct TreeNode* root){
    
    int nodexs = nodeNums(root);
    printf("nodeNums:%d\n",nodexs);
    int * vals = (int *)calloc(nodexs,sizeof(int));
    struct TreeNode** lists = (struct TreeNode**)calloc(nodexs,sizeof(struct TreeNode*));
    
    inordeHelp(root,vals,lists);
    qsort(vals,nodexs,sizeof(int),comap);

    for(int i=0; i<nodexs; i++)
    {
        lists[i]->val = vals[i];
    }

    free(vals);
    free(lists);
}
// @lc code=end

