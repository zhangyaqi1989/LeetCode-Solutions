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
    bool isSymmetric(TreeNode* root) {
        return helper(root, root);
    }
    
    bool helper(TreeNode * p, TreeNode * q)
    {
        if (p == nullptr || q == nullptr) return p == q;
        return p->val == q->val && helper(p->left, q->right) && helper(p->right, q->left);
    }
};