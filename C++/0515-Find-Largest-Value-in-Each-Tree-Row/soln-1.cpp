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
        vector<int> ans;
        if (root == nullptr) return ans;
        queue<TreeNode *> frontier;
        frontier.push(root);
        while (!frontier.empty()) {
            int sz = frontier.size();
            int mx = INT_MIN;
            for(int i = 0; i < sz; ++i) {
                TreeNode * node = frontier.front();
                frontier.pop();
                mx = max(mx, node->val);
                if (node->left != nullptr) frontier.push(node->left);
                if (node->right != nullptr) frontier.push(node->right);
            }
            ans.push_back(mx);
        }
        return ans;
    }
};
