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
    int goodNodes(TreeNode* root) {
        int ans = 0;
        dfs(root, -100000, &ans);
        return ans;
    }
    
private:
    void dfs(TreeNode * node, int mx, int * ans) {
        if(node != nullptr) {
            if(node->val >= mx) *ans += 1;
            mx = max(mx, node->val);
            dfs(node->left, mx, ans);
            dfs(node->right, mx, ans);
        }
    }
};
