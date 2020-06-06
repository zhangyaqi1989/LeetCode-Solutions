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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        return BuildTree(0, n - 1, nums);
    }
    
private:
    TreeNode * BuildTree(int lo, int hi, const vector<int> & nums) {
        if(lo > hi) return nullptr;
        // hi >= lo
        int mid = lo + (hi - lo) / 2;
        TreeNode * root = new TreeNode(nums[mid]);
        root->left = BuildTree(lo, mid - 1, nums);
        root->right = BuildTree(mid + 1, hi, nums);
        return root;
    }
};
