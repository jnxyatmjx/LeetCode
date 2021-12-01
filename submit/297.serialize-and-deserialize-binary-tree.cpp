/*
 * @lc app=leetcode id=297 lang=cpp
 *
 * [297] Serialize and Deserialize Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.

    void serialPreorder(TreeNode* root,std::string& res)
    {
        if(root == NULL)
        {
            res.append("#").append(",");
            return;
        }
        
        res.append(std::to_string(root->val)).append(",");

        serialPreorder(root->left,res);
        serialPreorder(root->right,res);
    }

    string serialize(TreeNode* root) {
        std::string res;
        
        serialPreorder(root,res);
        //printf("res:%s\n len:%td",res.c_str(),res.length());
        return std::move(res);
    }

    TreeNode* createNode(int val)
    {
        TreeNode * tep = new TreeNode(val);
        return tep;
    }

    // Decodes your encoded data to tree.
    TreeNode* deseriPreorder(std::list<std::string>& list_)
    {
        if(list_.empty()) return NULL;

        std::string c_ = std::move(list_.front());list_.pop_front();//printf("%s ",c_.c_str());
        if(c_.compare("#") == 0) return NULL;
        TreeNode* root = createNode(atoi(c_.c_str()));

        root->left = deseriPreorder(list_);
        root->right = deseriPreorder(list_);

        return root;
    }

    TreeNode* deserialize(string data) {
        std::list<std::string> clist;
        
        for(int i=0,j=0; i<data.size() && j<data.size(); j++)
        {
            if(data.at(j) == ',')
            {
                clist.push_back(data.substr(i,j-i));
                i = j+1;
            }
        }
        // for(const auto& m_:clist)
        //     printf("%s ",m_.c_str());
        // printf("\n");
        
        return deseriPreorder(clist);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end

