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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if (d == 1) {
            TreeNode* node = new TreeNode(v);
            node->left = root;
            return node;
        }
        vector<TreeNode*> row = {root};
        for(int i = 0; i < d - 2; ++i) {
            vector<TreeNode*> temp;
            for(auto node : row) {
                if (node->left != nullptr) temp.push_back(node->left);
                if (node->right != nullptr) temp.push_back(node->right);
            }
            swap(temp, row);
        }
        for(auto & node : row) {
            TreeNode* left = node->left;
            TreeNode* right = node->right;
            node->left = new TreeNode(v);
            node->right = new TreeNode(v);
            node->left->left = left;
            node->right->right = right;
        }
        return root;
    }
};
