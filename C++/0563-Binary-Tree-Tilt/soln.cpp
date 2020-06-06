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
    int findTilt(TreeNode* root) {
        int ans = 0;
        traverse(root, ans);
        return ans;
    }
    
    int traverse(TreeNode * node, int & ans) {
        if (node == nullptr) return 0;
        int l = traverse(node->left, ans);
        int r = traverse(node->right, ans);
        ans += abs(l - r);
        return l + r + node->val;
    }
};
