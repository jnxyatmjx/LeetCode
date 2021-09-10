/*
 * @lc app=leetcode id=652 lang=cpp
 *
 * [652] Find Duplicate Subtrees
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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, vector<TreeNode*>> map;
        vector<TreeNode*> dups;
        
        serialize_post(root, map);
        
        for (auto it = map.begin(); it != map.end(); it++)
            if (it->second.size() > 1) dups.push_back(it->second[0]);
        return dups;
    }
private:
    string serialize_post(TreeNode* node, unordered_map<string, vector<TreeNode*>>& map) {
        if (node == NULL) return "";
        
        std::string s_left = serialize_post(node->left, map);
        std::string s_righ = serialize_post(node->right, map);
        
        std::string s = "(" + s_left +std::to_string(node->val) + s_righ + ")";
        //string s = "(" + serialize_post(node->left, map) + to_string(node->val) + serialize_post(node->right, map) + ")";
        printf("%s\n",s.c_str());
        
        map[s].push_back(node);
        return s;
    }
};
// @lc code=end

