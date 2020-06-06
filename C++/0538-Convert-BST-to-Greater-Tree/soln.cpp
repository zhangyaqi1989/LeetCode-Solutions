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
    TreeNode* convertBST(TreeNode* root) {
        int acc = 0;
        traverse(root, acc);
        return root;
    }
    
    void traverse(TreeNode * node, int & acc)
    {
        if(node != nullptr)
        {
            traverse(node->right, acc);
            int temp = node->val;
            node->val += acc;
            acc += temp;
            traverse(node->left, acc);
        }
    }
};