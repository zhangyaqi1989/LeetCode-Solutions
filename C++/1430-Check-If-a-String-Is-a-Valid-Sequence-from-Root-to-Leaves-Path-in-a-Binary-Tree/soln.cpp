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
const int MOD = 1e9 + 7;

class Solution {
public:
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        // hash
        unordered_set<int> seen;
        dfs(root, 0, seen);
        int key = 0;
        for(int val : arr) {
            key = ((long long) key * 10 + val) % MOD;
        }
        return seen.find(key) != seen.end();
    }
private:
    void dfs(TreeNode * node, int path, unordered_set<int> & seen) {
        if(node != nullptr) {
            path = ((long long) path * 10 + node->val) % MOD;
            if(node->left == nullptr && node->right == nullptr) {
                seen.insert(path);
            }
            dfs(node->left, path, seen);
            dfs(node->right, path, seen);
        }
    }
};
