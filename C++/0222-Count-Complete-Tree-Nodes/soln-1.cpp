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
    int countNodes(TreeNode* root) {
        if (root == nullptr) return 0;
        int l = computeHeight(root->left), r = computeHeight(root->right);
        if (r < l) return (1 << r) + countNodes(root->left);
        else return (1 << l) + countNodes(root->right);
    }
    
private:
    int computeHeight(TreeNode * root) {
        if (root == nullptr) return 0;
        return max(computeHeight(root->left), computeHeight(root->right)) + 1;
    }
};
