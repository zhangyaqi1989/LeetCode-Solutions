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
    int rob(TreeNode* root) {
        // postprocess
        // [best_with_root, best_without_root]
        auto ans = Postorder(root);
        return max(ans.first, ans.second);
    }
    
private:
    // return [best_with_root, best_without_root]
    pair<int, int> Postorder(TreeNode * root) {
        if (root != nullptr) {
            auto l = Postorder(root->left);
            auto r = Postorder(root->right);
            return {root->val + l.second + r.second, max(l.first, l.second) + max(r.first, r.second)};
        }
        return {0, 0};
    }
};
