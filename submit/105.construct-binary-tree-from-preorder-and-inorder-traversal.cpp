/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
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
    std::map<int, int> inorderIdx;
    TreeNode* buildSubTree(vector<int>& inorder,int in_le,int in_ri,vector<int>& preorder,int pre_le,int pre_ri)
    {
        if(pre_le > pre_ri) return NULL;

        TreeNode* root = new TreeNode(preorder[pre_le]);
        // int subInorderRootIdx = in_le;
        // for(; subInorderRootIdx <= in_ri; subInorderRootIdx++)
        //     if(inorder[subInorderRootIdx] == root->val)
        //         break;
        int subInorderRootIdx = inorderIdx[root->val];
        
        // Use pe - ps = ie - is to get ???
        root->left  = buildSubTree(inorder,in_le,subInorderRootIdx-1,preorder,pre_le + 1, pre_le - in_le + subInorderRootIdx);
        root->right = buildSubTree(inorder,subInorderRootIdx+1,in_ri,preorder,pre_le - in_le + subInorderRootIdx + 1, pre_ri);   

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int treeNum = (int)preorder.size();
        if(treeNum <= 0) return NULL;

        //the index of inorder traversal
        for(int i = 0; i < treeNum; i++)
        {
            inorderIdx[inorder[i]] = i;
        }

        TreeNode* res = buildSubTree(inorder,0,treeNum-1,preorder,0,treeNum-1);
        return res;
    }
};
// @lc code=end

