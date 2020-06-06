/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode * suc = nullptr;
        dfs(root, &suc);
    }
    
private:
    void dfs(TreeNode * node, TreeNode ** suc) {
        // right - root - left
        if(node != nullptr) {
            dfs(node->right, suc);
            dfs(node->left, suc);
            // do the work
            node->right = *suc;
            node->left = nullptr;
            *suc = node;
        }
    } 
};
