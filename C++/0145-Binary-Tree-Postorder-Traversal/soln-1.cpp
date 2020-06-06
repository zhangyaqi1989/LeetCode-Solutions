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
    vector<int> postorderTraversal(TreeNode* root) {
        TreeNode * cur = root;
        vector<int> vals;
        stack<TreeNode *> stk;
        while (cur != nullptr || !stk.empty()) {
            while (cur != nullptr) {
                vals.push_back(cur->val);
                stk.push(cur);
                cur = cur->right;
            }
            cur = stk.top();
            stk.pop();
            cur = cur->left;
        }
        reverse(vals.begin(), vals.end());
        return vals;
    }
};
