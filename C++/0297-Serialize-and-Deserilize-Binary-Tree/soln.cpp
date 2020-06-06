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
        string ans = "";
        preorder(root, ans);
        return ans.substr(1);
    }
    
    void preorder(TreeNode * node, string & ans) {
        if (node == nullptr) {
            ans += " #";
        } else {
            ans += " " + to_string(node->val);
            preorder(node->left, ans);
            preorder(node->right, ans);
        }
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream iss(data);
        return build(iss);
    }
    
    TreeNode * build(istringstream & iss) {
        string token;
        iss >> token;
        if (token == "#") {
            return nullptr;
        } else {
            TreeNode * root = new TreeNode(stoi(token));
            root->left = build(iss);
            root->right = build(iss);
            return root;
        }
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
