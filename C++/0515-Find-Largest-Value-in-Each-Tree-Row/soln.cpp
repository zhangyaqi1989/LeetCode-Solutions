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
    vector<int> largestValues(TreeNode* root) {
        if (root == nullptr) return {};
        vector<int> ans;
        deque<TreeNode *> q;
        q.push_back(root);
        while (q.size()) {
            int mx = INT_MIN;
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                TreeNode * node = q.front();
                q.pop_front();
                mx = max(mx, node->val);
                if (node->left) q.push_back(node->left);
                if (node->right) q.push_back(node->right);
            }
            ans.push_back(mx);
        }
        return ans;
    }
};