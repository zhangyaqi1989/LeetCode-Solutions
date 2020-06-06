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
        suc = nullptr;
        dfs(root);
    }
    
    void dfs(TreeNode * node) {
        if (node != nullptr) {
            dfs(node->right);
            dfs(node->left);
            if (suc != nullptr) {
                node->right = suc;
                node->left = nullptr;
            }
            suc = node;
        }
    }
        
private:
    TreeNode * suc;
    
};
