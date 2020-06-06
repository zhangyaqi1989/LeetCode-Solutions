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
        // left right root
        vector<int> ans;
        stack<TreeNode *> stk;
        TreeNode * cur = root;
        while (!stk.empty() || cur != nullptr) {
            while(cur != nullptr) {
                ans.push_back(cur->val);
                stk.push(cur);
                cur = cur->right;
            }
            cur = stk.top();
            stk.pop();
            cur = cur->left;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
