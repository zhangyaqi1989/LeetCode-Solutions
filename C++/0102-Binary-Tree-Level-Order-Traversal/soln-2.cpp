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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == nullptr) return ans;
        queue<TreeNode *> frontier;
        frontier.push(root);
        while(!frontier.empty()) {
            vector<int> level;
            int sz = frontier.size();
            for(int i = 0; i < sz; ++i) {
                auto node = frontier.front();
                level.push_back(node->val);
                frontier.pop();
                if(node->left != nullptr) frontier.push(node->left);
                if(node->right != nullptr) frontier.push(node->right);
            }
            ans.push_back(level);
        }
        return ans;
    }
};
