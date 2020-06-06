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
    vector<vector<int>> findLeaves(TreeNode* root) {
        map<int, vector<int>> levels;
        post(root, levels);
        vector<vector<int>> ans;
        for(int l = 1; ; ++l) {
            auto it = levels.find(l);
            if (it == levels.end()) break;
            else ans.push_back(it->second);
        }
        return ans;
    }
    
    int post(TreeNode * node, map<int, vector<int>> & levels) {
        if (node == nullptr) return 0;
        int l = post(node->left, levels);
        int r = post(node->right, levels);
        int ans = max(l, r) + 1;
        levels[ans].push_back(node->val);
        return ans;
    }
};
