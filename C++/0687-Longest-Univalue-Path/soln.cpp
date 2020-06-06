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
    int longestUnivaluePath(TreeNode* root) {
        int ans = 0;
        helper(root, ans);
        return ans;
    }
    
    int helper(TreeNode* node, int& ans) {
        if (node == nullptr) return 0;
        int l = helper(node->left, ans);
        int r = helper(node->right, ans);
        l = (node->left && node->val == node->left->val) ? l + 1 : 0;
        r = (node->right && node->val == node->right->val) ? r + 1 : 0;
        ans = max(ans, l + r);
        return max(l, r);
    }
};
