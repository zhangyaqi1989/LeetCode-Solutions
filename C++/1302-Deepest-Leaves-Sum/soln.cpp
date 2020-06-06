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
    int deepestLeavesSum(TreeNode* root) {
        vector<TreeNode *> frontier = {root};
        int ans = 0;
        while(!frontier.empty()) {
            ans = 0;
            vector<TreeNode *> next_level;
            for(TreeNode * node : frontier) {
                ans += node->val;
                if (node->left != nullptr) next_level.push_back(node->left);
                if (node->right != nullptr) next_level.push_back(node->right);
            }
            swap(frontier, next_level);
        }
        return ans;
    }
};
