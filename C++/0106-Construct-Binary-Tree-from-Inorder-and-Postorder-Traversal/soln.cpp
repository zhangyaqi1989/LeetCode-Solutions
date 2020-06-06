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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return helper(inorder, 0, inorder.size(), postorder, 0, postorder.size());
    }
    
    TreeNode * helper(vector<int>& inorder, int i, int j, vector<int> & postorder, int ii, int jj)
    {
        if (ii >= jj) return NULL;
        int root_val = postorder[jj - 1];
        TreeNode * root = new TreeNode(root_val);
        auto it = find(inorder.begin() + i, inorder.begin() + j, root_val);
        int left = it - inorder.begin() - i;
        root->left = helper(inorder, i, i + left, postorder, ii, ii + left);
        root->right = helper(inorder, i+left+1, j, postorder, ii+left, jj-1);
        return root;
    }
};