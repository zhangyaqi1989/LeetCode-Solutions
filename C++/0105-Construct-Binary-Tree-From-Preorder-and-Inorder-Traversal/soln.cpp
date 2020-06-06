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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }
    
    TreeNode * helper(vector<int>& preorder, int i, int j, vector<int>& inorder, int ii, int jj)
    {
        if (i >= j) return NULL;
        int root_val = preorder[i];
        TreeNode * root = new TreeNode(root_val);
        auto it = find(inorder.begin() + ii, inorder.begin() + jj, root_val);
        int left = it - inorder.begin() - ii;
        root->left = helper(preorder, i + 1, i + 1 + left, inorder, ii, ii + left);
        root->right = helper(preorder, i + 1 + left, j, inorder, ii + left + 1, jj);
        return root;
    }
};