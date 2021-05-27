/*
 * @lc app=leetcode id=106 lang=cpp
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    std::map<int,int> inorderIdx;
    
    /*
        if the inorder index -> in_le , in_ri 
        and the postorder index -> po_le , po_ri 
        type size_t will ERROR

        !!!!!!!!type MUST int !!!!!!!!!
    */
    TreeNode* buildSubTree(vector<int>& inorder,int in_le,int in_ri, 
                     vector<int>& postorder,int po_le,int po_ri)
    {
        if( po_le > po_ri) return NULL;

        TreeNode* root = new TreeNode(postorder[po_ri]);
        // int subInorderRootIdx = in_le;
        // for(; subInorderRootIdx <= in_ri;subInorderRootIdx++)
        //     if(inorder[subInorderRootIdx] == root->val)
        //         break;
        int subInorderRootIdx = inorderIdx[root->val];
        
        root->left  = buildSubTree(inorder,in_le,subInorderRootIdx-1,postorder,po_le, po_le - in_le - 1 + subInorderRootIdx);
        root->right = buildSubTree(inorder,subInorderRootIdx+1,in_ri,postorder,po_ri - in_ri + subInorderRootIdx, po_ri - 1);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
        int treeNum = (int)inorder.size();
        if(treeNum <= 0) return NULL;
        
        //find the root index of inorder subtree
        for(int i = 0; i < treeNum; i++)
            inorderIdx[inorder[i]] = i;

        return buildSubTree(inorder,0,treeNum-1,postorder,0,treeNum-1);
    }
};
// @lc code=end

