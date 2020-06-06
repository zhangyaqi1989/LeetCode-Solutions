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
    TreeNode* increasingBST(TreeNode* root) {
        // right -> root -> left
        stack<TreeNode*> s;
        TreeNode * cur = root;
        TreeNode * pre = NULL;
        while (cur != nullptr || s.size() != 0) {
            while (cur != nullptr) {
                s.push(cur);
                cur = cur->right;
            }
            cur = s.top();
            TreeNode * left = cur->left;
            cur->left = NULL;
            cur->right = pre;
            pre = cur;
            s.pop();
            cur = left;
        }
        return pre;
    }
};