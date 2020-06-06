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
    int findBottomLeftValue(TreeNode* root) {
        int mx_level = 0, ans = root->val;
        preorder(root, 0, mx_level, ans);
        return ans;
    }
    
    void preorder(TreeNode * node, int level, int & mx_level, int & ans) {
        if (node != nullptr) {
            if (level > mx_level) {
                mx_level = level;
                ans = node->val;
            }
            preorder(node->left, level + 1, mx_level, ans);
            preorder(node->right, level + 1, mx_level, ans);
        }
    }
};
