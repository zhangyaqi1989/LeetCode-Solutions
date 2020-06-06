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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode * > s;
        TreeNode * cur = root;
        while (cur != NULL || !s.empty())
        {
            k--;
            while (cur != NULL)
            {
                s.push(cur);
                cur = cur -> left;
            }
            cur = s.top();
            s.pop();
            if (k == 0)
                return cur->val;
            cur = cur -> right;
        }
    }

};