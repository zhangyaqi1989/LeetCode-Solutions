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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) return {};
        vector<vector<int>> ans;
        queue<TreeNode *> frontier;
        frontier.push(root);
        while (!frontier.empty()) {
            int size = frontier.size();
            vector<int> level;
            for(int i = 0; i < size; ++i) {
                TreeNode * node = frontier.front();
                level.push_back(node->val);
                frontier.pop();
                if (node->left) frontier.push(node->left);
                if (node->right) frontier.push(node->right);
            }
            ans.push_back(level);
        }
        return ans;
    }
};
