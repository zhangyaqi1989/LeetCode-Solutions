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
    void flatten(TreeNode* root) {
        TreeNode * suc = nullptr;
        dfs(root, suc);
    }
    
    void dfs(TreeNode * node, TreeNode * & suc) {
        if (node != nullptr) {
            dfs(node->right, suc);
            dfs(node->left, suc);
            if (suc != nullptr) {
                node->right = suc;
                node->left = nullptr;
            }
            suc = node;
        }
    }
    
};
