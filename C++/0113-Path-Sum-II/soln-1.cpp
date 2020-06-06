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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> path;
        vector<vector<int>> ans;
        dfs(root, sum, &path, &ans);
        return ans;
    }
    
private:
    void dfs(TreeNode * root, int sum, vector<int> * path, vector<vector<int>> * ans) {
        if (root != nullptr) {
            path->push_back(root->val);
            sum -= root->val;
            if (root->left == nullptr && root->right == nullptr) {
                if (sum == 0) {
                    ans->push_back(*path);
                }
            }
            if (root->left != nullptr) dfs(root->left, sum, path, ans);
            if (root->right != nullptr) dfs(root->right, sum, path, ans);
            path->pop_back();
        }
    }
};
