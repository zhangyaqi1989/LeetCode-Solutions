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
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        TreeNode * node = new TreeNode(val);
        if (root == nullptr) return node;
        if (val > root->val) {
            node->left = root;
            return node;
        } else {
            TreeNode * right = insertIntoMaxTree(root->right, val);
            root->right = right;
            return root;
        }
    }
};
