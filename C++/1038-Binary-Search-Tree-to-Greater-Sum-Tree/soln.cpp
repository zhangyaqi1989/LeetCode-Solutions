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
    TreeNode* bstToGst(TreeNode* root) {
        int acc = 0;
        Dfs(root, acc);
        return root;
    }

private:
    void Dfs(TreeNode * node, int & acc) {
        if(node != nullptr) {
            Dfs(node->right, acc);
            acc += node->val;
            node->val = acc;
            Dfs(node->left, acc);
        }
    }
};
