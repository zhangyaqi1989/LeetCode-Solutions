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
    int minDiffInBST(TreeNode* root) {
        int pre = INT_MAX;
        int ans = INT_MAX;
        inorder(root, pre, ans);
        return ans;
    }
    
    void inorder(TreeNode * node, int & pre, int & ans) {
        if (node != nullptr) {
            inorder(node->left, pre, ans);
            if (pre != INT_MAX && node->val - pre < ans) {
                ans = node->val - pre;
            }
            pre = node->val;
            inorder(node->right, pre, ans);
        }
    }
};
