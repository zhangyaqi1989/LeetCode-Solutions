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
    bool isValidBST(TreeNode* root) {
        TreeNode * pre = NULL;
        stack<TreeNode *> s;
        TreeNode * cur = root;
        while (cur != NULL || !s.empty())
        {
            while(cur != NULL)
            {
                s.push(cur);
                cur = cur -> left;
            }
            cur = s.top();
            s.pop();
            if (pre != NULL && cur -> val <= pre -> val) return false;
            pre = cur;
            cur = cur -> right;
        }
        return true;
    }
};