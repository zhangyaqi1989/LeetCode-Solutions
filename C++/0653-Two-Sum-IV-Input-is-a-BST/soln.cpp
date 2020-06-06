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
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> s;
        return dfs(root, s, k);
    }
    
    bool dfs(TreeNode * node, unordered_set<int>& s, int k)
    {
        if(!node) return false;
        if (s.count(k - node->val)) return true;
        s.insert(node->val);
        return dfs(node->left, s, k) || dfs(node->right, s, k);
    }
};