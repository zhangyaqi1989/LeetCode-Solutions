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
    int longestConsecutive(TreeNode* root) {
        if (root == nullptr) return 0;
        int ans = 1;
        traverse(root, 1, nullptr, ans);
        return ans;
    }
    
    void traverse(TreeNode * node, int path, TreeNode * parent, int & ans) {
        if (node != nullptr) {
            if (parent != nullptr) {
                if (parent->val + 1 == node->val) {
                    ++path;
                    ans = max(path, ans);
                } else {
                    path = 1;
                }
            }
            traverse(node->left, path, node, ans);
            traverse(node->right, path, node, ans);
        }
    }
};
