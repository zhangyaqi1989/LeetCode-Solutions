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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return nullptr;
        auto mx_it = max_element(nums.begin(), nums.end());
        int val = *mx_it;
        vector<int> left(nums.begin(), mx_it);
        vector<int> right(mx_it + 1, nums.end());
        TreeNode * root = new TreeNode(val);
        root->left = constructMaximumBinaryTree(left);
        root->right = constructMaximumBinaryTree(right);
        return root;
    }
};
