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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> vals;
        helper(root, vals);
        return vals;
    }
    
    void helper(TreeNode * node, vector<int> & vals)
    {
        if(node != NULL)
        {
            vals.push_back(node->val);
            helper(node->left, vals);
            helper(node->right, vals);
        }

    }
};