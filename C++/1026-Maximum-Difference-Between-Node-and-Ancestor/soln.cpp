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
    int maxAncestorDiff(TreeNode* root) {
        int ans = 0;
        dfs(root, INT_MAX, INT_MIN, ans);
        return ans;
    }
    
    void dfs(TreeNode * node, int mn, int mx, int & ans) {
        if (node == nullptr) {
            ans = max(ans, mx - mn);
        } else {
            dfs(node->left, min(mn, node->val), max(mx, node->val), ans);
            dfs(node->right, min(mn, node->val), max(mx, node->val), ans);
        }
    }
};
