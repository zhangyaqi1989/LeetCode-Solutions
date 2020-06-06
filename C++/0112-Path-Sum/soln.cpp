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
    bool hasPathSum(TreeNode* root, int sum) {
        return helper(root, sum);
    }
    
    bool helper(TreeNode * node, int target)
    {
        if(node == nullptr) return false;
        else
        {
            if(node->left == nullptr && node->right == nullptr)
            {
                if(node->val == target) return true;
                else return false;
            } else
            {
                return helper(node->left, target - node->val) || helper(node->right, target - node->val);
            }
        }
    }
};