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
        int mx = 0;
        helper(root, 0, 0, mx);
        return mx;
    }
    
    void helper(TreeNode * node, int parent, int cur, int& mx) {
        if(node != nullptr) {
            if (node->val == parent + 1) {
                ++cur;
            } else {
                cur = 1;
            }
            mx = max(mx, cur);
            if (node->left != nullptr){
                helper(node->left, node->val, cur, mx);
            }
            if (node->right != nullptr){
                helper(node->right, node->val, cur, mx);
            }
        }

    }
};
