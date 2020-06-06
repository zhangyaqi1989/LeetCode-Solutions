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
    bool isValidBST(TreeNode* root) {
        TreeNode * prev = nullptr;
        return valid(root, prev);
    }
    
    bool valid(TreeNode * node, TreeNode * & prev) {
        if (node != nullptr) {
            if (!valid(node->left, prev)) return false;
            if (prev != nullptr && prev->val >= node->val) return false;
            prev = node;
            return valid(node->right, prev);
        }
        return true;
    }
    
    
};
