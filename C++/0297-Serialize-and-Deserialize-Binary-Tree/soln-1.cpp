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
        string data;
        preorder(root, data);
        return data.substr(1);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> tokens;
        int i = 0, n = data.length();
        while (true) {
            int j = data.find(' ', i);
            if(j == string::npos) {
                tokens.push_back(data.substr(i, n - i));
                break;
            } else {
                tokens.push_back(data.substr(i, j - i));
                i = j + 1;
            }
        }
        // reverse(tokens.begin(), tokens.end());
        int idx = 0;
        return build(tokens, idx);
    }
    
private:
    TreeNode * build(vector<string> & tokens, int & idx) {
        // string val = tokens.back();
        // tokens.pop_back();
        string val = tokens[idx++];
        if (val == "#") return nullptr;
        else {
            TreeNode * root = new TreeNode(stoi(val));
            root->left = build(tokens, idx);
            root->right = build(tokens, idx);
            return root;
        }
    }
    
    void preorder(TreeNode * node, string & data) {
        if (node != nullptr) {
            data += " " + to_string(node->val);
            preorder(node->left, data);
            preorder(node->right, data);
        } else {
            data += " #";
        }
    }
    
    
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
