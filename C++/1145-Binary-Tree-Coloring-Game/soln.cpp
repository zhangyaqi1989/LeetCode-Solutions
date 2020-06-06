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
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        int left = 0, right = 0;
        dfs(root, left, right, x);
        return max(max(left, right), n - left - right - 1) > n / 2;
    }
    
    int dfs(TreeNode * node, int & left, int & right, int x) {
        if (node != nullptr) {
            int l = dfs(node->left, left, right, x);
            int r = dfs(node->right, left, right, x);
            if (node->val == x) {
                left = l;
                right = r;
            }
            return l + r + 1;
        } else {
            return 0;
        }
    }
};
