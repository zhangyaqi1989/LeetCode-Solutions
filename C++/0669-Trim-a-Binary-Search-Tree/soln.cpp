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
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if (L > R || root == nullptr) return nullptr;
        if (root->val >= L && root->val <= R) {
            root->left = trimBST(root->left, L, root->val);
            root->right = trimBST(root->right, root->val, R);
            return root;
        } else if (root->val < L) {
            return trimBST(root->right, L, R);
        } else {
            return trimBST(root->left, L, R);
        }
    }
};
