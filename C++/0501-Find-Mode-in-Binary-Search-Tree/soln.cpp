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
    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> counter;
        dfs(root, counter);
        int mx = 0;
        vector<int> modes;
        for(auto & p : counter) {
            if (p.second == mx) {
                modes.push_back(p.first);
            } else if (p.second > mx) {
                mx = p.second;
                modes.clear();
                modes.push_back(p.first);
            }
        }
        return modes;
    }
    
    void dfs(TreeNode* node, unordered_map<int, int> & counter) {
        if (node != nullptr) {
            ++counter[node->val];
            dfs(node->left, counter);
            dfs(node->right, counter);
        }
    }
};
