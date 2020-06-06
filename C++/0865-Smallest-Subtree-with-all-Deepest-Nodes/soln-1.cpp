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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        pair<int, TreeNode *> ans = postorder(root);
        return ans.second;
    }
    
    pair<int, TreeNode *> postorder(TreeNode * root) {
        if (root == nullptr) return {0, nullptr};
        auto l = postorder(root->left);
        auto r = postorder(root->right);
        if (l.first > r.first) return {l.first + 1, l.second};
        else if (r.first > l.first) return {r.first + 1, r.second};
        else return {l.first + 1, root};
    }
    
};
