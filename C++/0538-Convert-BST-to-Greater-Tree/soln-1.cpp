/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        int acc = 0;
        stack<TreeNode *> st;
        TreeNode * cur = root;
        while(cur != nullptr || !st.empty()) {
            while(cur != nullptr) {
                st.push(cur);
                cur = cur->right;
            }
            cur = st.top();
            st.pop();
            acc += cur->val;
            cur->val = acc;
            cur = cur->left;
        }
        return root;
    }
};
