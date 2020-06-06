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
        unordered_map<int, vector<int>> m;
        traverse(root, m);
        vector<vector<int>> ans;
        for(int lev = 1; lev <= m.size(); ++lev)
        {
            ans.push_back(m[lev]);
        }
        return ans;
    }
    int traverse(TreeNode * root, unordered_map<int, vector<int>> & m)
    {
        if(root == nullptr) return 0;
        int left = traverse(root->left, m);
        int right = traverse(root->right, m);
        int level = max(left, right) + 1;
        m[level].push_back(root->val);
        return level;
    }
};