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
    string smallestFromLeaf(TreeNode* root) {
        if(!root) return "";
        if(!root->left && !root->right) return string(1, 'a' + root->val);
        if(!root->left || !root->right) {
            TreeNode * child;
            if (root->left) child = root->left;
            else child = root->right;
            return smallestFromLeaf(child) + string(1, 'a' + root->val);
        } else {
            string left = smallestFromLeaf(root->left);
            string right = smallestFromLeaf(root->right);
            if (left < right) return left + string(1, 'a' + root->val);
            else return right + string(1, 'a' + root->val);
        }
    }
};
