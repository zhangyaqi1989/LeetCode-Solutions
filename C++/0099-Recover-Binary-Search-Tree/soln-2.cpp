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
        // 1 2 3 4 5
        // 1 5 3 4 2
        TreeNode * cur = root;
        stack<TreeNode *> st;
        TreeNode * pre = nullptr;
        TreeNode * l = nullptr;
        TreeNode * r = nullptr;
        while (!st.empty() || cur != nullptr) {
            while(cur != nullptr) {
                st.push(cur);
                cur = cur->left;
            }
            cur = st.top();
            st.pop();
            if (pre != nullptr) {
                if (cur->val < pre->val) {
                    r = cur;
                    if (l == nullptr) l = pre;
                    else break;
                }
            }
            pre = cur;
            cur = cur->right;
        }
        int temp = l->val;
        l->val = r->val;
        r->val = temp;
    }
};
