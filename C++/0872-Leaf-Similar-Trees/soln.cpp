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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> vals1, vals2;
        inorder(root1, vals1);
        inorder(root2, vals2);
        return vals1.size() == vals2.size() && equal(vals1.begin(), vals1.end(), vals2.begin());
    }
    
    void inorder(TreeNode * node, vector<int> & vals) {
        if (node != nullptr) {
            inorder(node->left, vals);
            if (node->left == nullptr && node->right == nullptr) {
                vals.push_back(node->val);
            }
            inorder(node->right, vals);
        }
    }
};
