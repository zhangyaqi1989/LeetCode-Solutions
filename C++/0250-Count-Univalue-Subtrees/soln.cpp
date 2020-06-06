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
    int countUnivalSubtrees(TreeNode* root) {
        int ans = 0;
        helper(root, ans);
        return ans;
    }
    
    pair<int, int> helper(TreeNode * node, int & ans) {
        if (node == nullptr) return {INT_MAX, INT_MIN};
        else {
            auto lp = helper(node->left, ans);
            auto rp = helper(node->right, ans);
            int mn = min(lp.first, rp.first), mx = max(lp.second, rp.second);
            mn = min(mn, node->val), mx = max(mx, node->val);
            if (mn == mx) ++ans;
            return {mn, mx};
        }
    }
};
