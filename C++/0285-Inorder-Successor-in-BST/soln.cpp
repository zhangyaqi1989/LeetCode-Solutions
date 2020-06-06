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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode * ans = nullptr;
        TreeNode * cur = root;
        TreeNode * pre = nullptr;
        stack<TreeNode *> s;
        while (cur != nullptr || !s.empty()) {
            while (cur != nullptr) {
                s.push(cur);
                cur = cur->left;
            }
            cur = s.top();
            s.pop();
            if (pre == p) ans = cur;
            pre = cur;
            cur = cur->right;
        }
        return ans;
    }
};
