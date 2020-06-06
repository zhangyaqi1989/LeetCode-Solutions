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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        traverse(root, 1, ans);
        return ans;
    }
    
    void traverse(TreeNode * node, int level, vector<int> & ans) {
        if (node != NULL) {
            if(ans.size() < level) ans.push_back(node->val);
            traverse(node->right, level + 1, ans);
            traverse(node->left, level + 1, ans);
        }
    }
};