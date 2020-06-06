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
    string smallestFromLeaf(TreeNode* root) {
        string str = "";
        string ans = "|";
        traverse(root, str, ans);
        return ans;
    }
    
    void traverse(TreeNode * node, string str, string & ans) {
        if (node == nullptr) return;
        if (node->left == nullptr && node->right == nullptr) {
            str = string(1, 'a' + node->val) + str;
            if (str < ans) ans = str;
            return;
        }
        traverse(node->left, string(1, 'a' + node->val) + str, ans);
        traverse(node->right, string(1, 'a' + node->val) + str, ans);
    }
};
