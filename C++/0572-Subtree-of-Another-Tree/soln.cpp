/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        string sstr = encode(s);
        string tstr = encode(t);
        return sstr.find(tstr) != string::npos;
    }
    
    string encode(TreeNode *node) {
        if (node == nullptr) return "";
        string l = encode(node->left);
        string r = encode(node->right);
        return "^" + to_string(node->val) + l + r + "$";
    }
};
