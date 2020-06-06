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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode *> ans;
        for(int num : to_delete) deletes.insert(num);
        dfs(root, true, ans);
        return ans;
    }
    
    TreeNode * dfs(TreeNode * node, bool is_root, vector<TreeNode *> & ans) {
        if (node == nullptr) return nullptr;
        bool is_delete = deletes.find(node->val) != deletes.end();
        node->left = dfs(node->left, is_delete, ans);
        node->right = dfs(node->right, is_delete, ans);
        if (!is_delete && is_root) ans.push_back(node);
        return is_delete ? nullptr : node;
    }
private:
    set<int> deletes;
};
