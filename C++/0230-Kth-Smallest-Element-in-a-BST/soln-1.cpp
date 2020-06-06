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
    int kthSmallest(TreeNode* root, int k) {
        int val;
        inorder(root, k, val);
        return val;
    }
    
    void inorder(TreeNode * node, int & k, int & val) {
        if (k > 0 && node != nullptr) {
            inorder(node->left, k, val);
            if (--k == 0) val = node->val;
            inorder(node->right, k, val);
        }
    }
};
