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
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        longestPathDown(root, ans);
        return ans > 0 ? ans - 1 : 0;
    }
    
private:
    int longestPathDown(TreeNode * node, int & ans) {
        if (node == nullptr) return 0;
        int l = longestPathDown(node->left, ans);
        int r = longestPathDown(node->right, ans);
        ans = max(l + r + 1, ans);
        return 1 + max(l, r);
    }
};
