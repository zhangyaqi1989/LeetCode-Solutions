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
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        return Dfs(arr, 0, root);
    }
    
private:
    bool Dfs(const vector<int> & arr, size_t idx, TreeNode * node) {
        if(idx == arr.size() - 1) {
            return node != nullptr && node->left == nullptr && node->right == nullptr && node->val == arr.back();
        }
        return node != nullptr && node->val == arr[idx] && (Dfs(arr, idx + 1, node->left) || Dfs(arr, idx + 1, node->right)); 
    }
};
