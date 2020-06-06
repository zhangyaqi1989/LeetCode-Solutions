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
    void recoverTree(TreeNode* root) {
        stack<TreeNode*> stk;
        TreeNode * x = nullptr;
        TreeNode * y = nullptr;
        TreeNode * pred = nullptr;
        TreeNode * cur = root;
        while (!stk.empty() || cur != nullptr) {
            while (cur != nullptr) {
                stk.push(cur);
                cur = cur->left;
            }
            cur = stk.top();
            stk.pop();
            if (pred != nullptr && cur->val < pred->val) {
                y = cur;
                if (x != nullptr) {
                    break;
                } else {
                    x = pred;
                }
            }
            pred = cur;
            cur = cur->right;
        }
        int temp = x->val;
        x->val = y->val;
        y->val = temp;
    }
};
