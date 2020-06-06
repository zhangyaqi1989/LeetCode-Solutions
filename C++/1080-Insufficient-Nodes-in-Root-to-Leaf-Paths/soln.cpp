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
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        TreeNode* ans;
        int mx;
        tie(ans, mx) = postOrder(root, limit);
        return ans;
    }
    
    pair<TreeNode *, int> postOrder(TreeNode * node, int limit) {
        if (node != nullptr) {
            int l_mx, r_mx;
            tie(node->left, l_mx) = postOrder(node->left, limit - node->val);
            tie(node->right, r_mx) = postOrder(node->right, limit - node->val);
            int mx = max(l_mx, r_mx) + node->val;
            if (mx >= limit) return {node, mx};
            else return {nullptr, mx};
        } else {
            return {nullptr, 0};
        }
    }
};
