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
    vector<TreeNode*> splitBST(TreeNode* root, int V) {
        if (root == nullptr) return {nullptr, nullptr};
        if (root->val == V) {
            TreeNode * right = root->right;
            root->right = nullptr;
            return {root, right};
        }
        else if (root->val < V) {
            vector<TreeNode*> ans = splitBST(root->right, V);
            root->right = ans[0];
            return {root, ans[1]};
        } else {
            vector<TreeNode*> ans = splitBST(root->left, V);
            root->left = ans[1];
            return {ans[0], root};
        }
    }
};
