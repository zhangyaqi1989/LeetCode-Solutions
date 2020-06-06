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
    int widthOfBinaryTree(TreeNode* root) {
        if (root == nullptr) return 0;
        long long ans = 0;
        queue<pair<TreeNode*, long long>> frontier;
        frontier.push({root, 0LL});
        long long mod = INT_MAX;
        while (!frontier.empty()) {
            int sz = frontier.size();
            long long mx = INT_MIN, mn = INT_MAX;
            for(int i = 0; i < sz; ++i) {
                auto p = frontier.front(); frontier.pop();
                TreeNode * node = p.first;
                long long col = p.second;
                mx = max(col, mx);
                mn = min(col, mn);
                if (node->left != nullptr) frontier.push({node->left, col * 2 % mod});
                if (node->right != nullptr) frontier.push({node->right, (col * 2 + 1) % mod});
            }
            ans = max(ans, mx - mn + 1);
        }
        return ans;
        
    }
};
