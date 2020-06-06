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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> vals;
        stack<TreeNode *> s;
        TreeNode * cur = root;
        while (cur != NULL || !s.empty())
        {
            while(cur != NULL)
            {
                vals.push_back(cur->val);
                s.push(cur);
                cur = cur->left;
            }
            cur = s.top();
            s.pop();
            cur = cur->right;
        }
        return vals;
    }
};