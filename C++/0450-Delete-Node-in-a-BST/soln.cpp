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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) return root;
        if (root->val == key) {
            // discuss its child
            if (root->left == nullptr && root->right == nullptr)
                return nullptr;
            if (root->left) {
                TreeNode * cur = root->left;
                while (cur->right) cur = cur->right;
                root->val = cur->val;
                root->left = deleteNode(root->left, root->val);
            } else {
                TreeNode * cur = root->right;
                while (cur->left) cur = cur->left;
                root->val = cur->val;
                root->right = deleteNode(root->right, root->val);
            }
        } else if (root->val < key) {
            root->right = deleteNode(root->right, key);
        } else {
            root->left = deleteNode(root->left, key);
        }
        return root;
    }
};
