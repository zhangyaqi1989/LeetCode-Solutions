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
    int getMinimumDifference(TreeNode* root) {
        int pre = -1, ans = INT_MAX;
        stack<TreeNode*> s;
        TreeNode* cur = root;
        while (cur || !s.empty()) {
            while(cur) {
                s.push(cur);
                cur = cur->left;
            }
            cur = s.top();
            s.pop();
            if (pre != -1)
                ans = min(ans, cur->val - pre);
            pre = cur->val;
            cur = cur->right;
        }
        return ans;
    }
};
