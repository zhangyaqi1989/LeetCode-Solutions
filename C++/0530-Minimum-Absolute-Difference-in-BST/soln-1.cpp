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
    int getMinimumDifference(TreeNode* root) {
        stack<TreeNode *> st;
        TreeNode * cur = root;
        int ans = INT_MAX;
        int pre = -1;
        while(cur != nullptr || !st.empty()) {
            while(cur != nullptr) {
                st.push(cur);
                cur = cur->left;
            }
            cur = st.top();
            st.pop();
            if(pre != -1) {
                ans = min(ans, cur->val - pre);
            }
            pre = cur->val;
            cur = cur->right;
        }
        return ans;
    }
};
