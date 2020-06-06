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
        // <= and >
        if (root == nullptr) return {nullptr, nullptr};
        if (root->val <= V) {
            vector<TreeNode *> temp = splitBST(root->right, V);
            root->right = temp[0];
            return {root, temp[1]};
        } else {
            // root->val > V;
            vector<TreeNode *> temp = splitBST(root->left, V);
            root->left = temp[1];
            return {temp[0], root};
        }
    }
};
