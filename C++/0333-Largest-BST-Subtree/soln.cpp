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
    int largestBSTSubtree(TreeNode* root) {
        int ans = 0;
        traverse(root, ans);
        return ans;
    }
    
    vector<int> traverse(TreeNode * node, int & ans) {
        if (node == nullptr) return {0, INT_MAX, INT_MIN, 1};
        vector<int> left = traverse(node->left, ans);
        vector<int> right = traverse(node->right, ans);
        int ln = left[0], lmn = left[1], lmx = left[2], lb = left[3];
        int rn = right[0], rmn = right[1], rmx = right[2], rb = right[3];
        int isb = 0;
        if (lb && rb && lmx < node->val && node->val < rmn) {
            isb = 1;
            ans = max(ans, ln + rn + 1);
        }
        return {ln + rn + 1, min(node->val, min(lmn, rmn)), max(node->val, max(lmx, rmx)), isb};
    }
};
