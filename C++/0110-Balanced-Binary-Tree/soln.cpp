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
    bool isBalanced(TreeNode* root) {
        return check(root) != -1;
    }
    
    int check(TreeNode * node) {
        if (node == nullptr) return 0;
        int left = check(node->left);
        int right = check(node->right);
        if (left == -1 || right == -1 || abs(left - right) > 1)
            return -1;
        return 1 + max(left, right);
    }
};