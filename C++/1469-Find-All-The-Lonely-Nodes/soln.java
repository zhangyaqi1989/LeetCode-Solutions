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
    vector<int> getLonelyNodes(TreeNode* root) {
        vector<int> lonely_nodes;
        Dfs(root, & lonely_nodes);
        return lonely_nodes;
    }
    
private:
    void Dfs(TreeNode * node, vector<int> * lonely_nodes) {
        if(node != nullptr) {
            if(node->left == nullptr && node->right != nullptr) {
                lonely_nodes->push_back(node->right->val);
            }
            if(node->left != nullptr && node->right == nullptr) {
                lonely_nodes->push_back(node->left->val);
            }
            Dfs(node->left, lonely_nodes);
            Dfs(node->right, lonely_nodes);
        }
    }
};
