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
    bool isUnivalTree(TreeNode* root) {
        stack<TreeNode *> st;
        TreeNode * cur = root;
        bool set_value = false;
        int value = -1;
        while(cur != nullptr || !st.empty()) {
            while(cur != nullptr) {
                st.push(cur);
                cur = cur->left;
            }
            cur = st.top();
            st.pop();
            if(!set_value) {
                value = cur->val;
                set_value = true;
            }else{
                if(value != cur->val) return false;
            }
            cur = cur->right;
        }
        return true;
    }
};
