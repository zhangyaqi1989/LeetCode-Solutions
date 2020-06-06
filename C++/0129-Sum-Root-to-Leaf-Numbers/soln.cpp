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
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        helper(root, 0, ans);
        return ans;
    }
    
    void helper(TreeNode *node, int acc, int & ans)
    {
        if (node != nullptr)
        {
            if(node->left == nullptr && node->right == nullptr)
            {
                ans += acc * 10 + node->val;
            } else
            {
                helper(node->left, acc * 10 + node->val, ans);
                helper(node->right, acc * 10 + node->val, ans);
            }
        }
    }
};