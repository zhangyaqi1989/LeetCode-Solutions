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
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode * cur = root;
        stack<TreeNode *> s;
        vector<int> vals;
        while(cur != NULL || !s.empty())
        {
            while(cur != NULL)
            {
                s.push(cur);
                cur = cur -> left;
            }
            cur = s.top();
            s.pop();
            vals.push_back(cur->val);
            cur = cur -> right;
        }
        return vals;
    }
};