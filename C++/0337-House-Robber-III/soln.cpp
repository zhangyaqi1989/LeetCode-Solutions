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
    int rob(TreeNode* root) {
        int rob = 0;
        int not_rob = 0;
        helper(root, rob, not_rob);
        return max(rob, not_rob);
    }
    
    void helper(TreeNode * node, int & rob, int & not_rob) {
        if (node == nullptr) {
            rob = 0;
            not_rob = 0;
            return;
        }
        int left_rob = 0, left_not_rob = 0;
        int right_rob = 0, right_not_rob = 0;
        helper(node->left, left_rob, left_not_rob);
        helper(node->right, right_rob, right_not_rob);
        rob = node->val + left_not_rob + right_not_rob;
        not_rob = max(left_rob, left_not_rob) + max(right_rob, right_not_rob);
    }
};
