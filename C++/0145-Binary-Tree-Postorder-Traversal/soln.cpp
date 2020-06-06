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
        vector<int> ans;
        TreeNode * cur = root;
        stack<TreeNode *> s;
        while (cur != nullptr || s.size()) {
            while (cur != nullptr) {
                ans.push_back(cur->val);
                s.push(cur);
                cur = cur->right;
            }
            cur = s.top();
            s.pop();
            cur = cur->left;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};