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
    TreeNode* pruneTree(TreeNode* root) {
        int ans = helper(root);
        return ans == 0 ? nullptr : root;
    }
    
    int helper(TreeNode * node) {
        if (node == nullptr) return 0;
        int left = helper(node->left);
        int right = helper(node->right);
        if (left == 0) node->left = nullptr;
        if (right == 0) node->right = nullptr;
        return node->val + left + right;
    }
};
