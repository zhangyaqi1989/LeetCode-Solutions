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
    int countNodes(TreeNode* root) {
        if (root == nullptr) return 0;
        int ld = depth(root->left);
        int rd = depth(root->right);
        if (ld == rd) {
            return pow(2, ld) + countNodes(root->right);
        } else {
            return pow(2, rd) + countNodes(root->left);
        }
    }
    
    int depth(TreeNode * node) {
        if (node == nullptr) return 0;
        return 1 + depth(node->left);
    }
};
