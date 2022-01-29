/*
 * @lc app=leetcode id=449 lang=cpp
 *
 * [449] Serialize and Deserialize BST
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
    string serialize(TreeNode* root) {
        ostringstream os;
        serialize(root, os);
        printf("%s\n",os.str().c_str());
        return os.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream is(data);
        return deserialize(is);
    }

    void serialize(TreeNode* root, ostringstream& os) {
        if (root==NULL) os << "# ";
        else {
            os << root->val << " "; // the space split the numbers for istringstream
            serialize(root->left, os);
            serialize(root->right, os);
        }
    }
    
    TreeNode* deserialize(istringstream& is) {
        string val = "";
        is >> val;
        if (val == "#") return NULL;
        TreeNode* node = new TreeNode(stoi(val));
        node->left = deserialize(is);
        node->right = deserialize(is);
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
// @lc code=end

