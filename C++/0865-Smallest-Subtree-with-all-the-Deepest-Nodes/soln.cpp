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
        auto ans = helper(root);
        return ans.second;
    }
    
    pair<int, TreeNode *> helper(TreeNode * node) {
        if (node != nullptr) {
            auto l = helper(node->left);
            auto r = helper(node->right);
            int depth = 0;
            TreeNode * root;
            if (l.first == r.first) {
                depth = l.first + 1;
                root = node;
            } else if (l.first < r.first) {
                depth = r.first + 1;
                root = r.second;
            } else {
                depth = l.first + 1;
                root = l.second;
            }
            return {depth, root};
        } else {
            return {0, nullptr};
        }
    }
};
