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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == nullptr) return ans;
        vector<TreeNode *> frontier;
        frontier.push_back(root);
        int idx = 0;
        while(!frontier.empty()) {
            vector<int> level;
            vector<TreeNode *> next_level;
            for(TreeNode * node : frontier) {
                level.push_back(node->val);
                if(node->left != nullptr) next_level.push_back(node->left);
                if(node->right != nullptr) next_level.push_back(node->right);
            }
            if(idx % 2 == 1) reverse(level.begin(), level.end());
            ans.push_back(level);
            ++idx;
            swap(frontier, next_level);
        }
        return ans;
    }
};
