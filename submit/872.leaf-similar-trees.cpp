/*
 * @lc app=leetcode id=872 lang=cpp
 *
 * [872] Leaf-Similar Trees
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
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        
        string s1,s2;

        hlp(root1,s1);
        hlp(root2,s2);
        
        return s1.compare(s2) == 0;
    }
//[3,5,1,6,2,9,8,null,null,7,14]\n[3,5,1,6,71,4,2,null,null,null,null,null,null,9,8]\n
/*
s1:6-7-14-9-8-  <>671498
s2:6-71-4-9-8-  <>671498
*/
    void hlp(TreeNode* root,string& leaves)
    {
        if(root == NULL) return;
        //if(root->left==NULL && root->right==NULL)
        //    leaves += to_string(root->val)+".";
        
        hlp(root->left,leaves);
        hlp(root->right,leaves);

        if(root->left==NULL && root->right==NULL)
            leaves += to_string(root->val)+".";
    }
};
// @lc code=end

