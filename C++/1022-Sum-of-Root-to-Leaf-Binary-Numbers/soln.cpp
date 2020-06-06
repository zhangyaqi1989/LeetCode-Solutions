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
    const long long mod = 1000000007LL;
public:
    int sumRootToLeaf(TreeNode* root) {
        long long ans = 0LL;
        helper(root, 0LL, ans);
        return ans;
    }
    
    void helper(TreeNode * node, long long path, long long & ans) {
        if (node != nullptr) {
            path = (path * 2 + node->val) % mod;
            if (node->left == nullptr && node->right == nullptr) {
                ans = (ans + path) % mod;
            }
            helper(node->left, path, ans);
            helper(node->right, path, ans);
        }
    }
};
