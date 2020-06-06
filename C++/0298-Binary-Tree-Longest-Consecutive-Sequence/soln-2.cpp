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
    int longestConsecutive(TreeNode* root) {
        int soln = 0;
        dfs(root, 1, soln);
        return soln;
    }
    
private:
    void dfs(TreeNode * node, int path, int & ans) {
        if (node != nullptr) {
            ans = max(path, ans);
            if (node->left != nullptr) {
                dfs(node->left, node->val + 1 == node->left->val ? path + 1 : 1, ans);
            }
            if (node->right != nullptr) {
                dfs(node->right, node->val + 1 == node->right->val ? path + 1 : 1, ans);
            }
        }
    }
};
