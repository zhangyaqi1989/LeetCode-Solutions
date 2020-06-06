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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = preorder.size();
        return helper(preorder, 0, n);
    }
    
    TreeNode* helper(vector<int> & preorder, int lo, int hi) {
        // cout << lo << " " << hi << endl;
        if (hi <= lo) return nullptr;
        int root_val = preorder[lo];
        TreeNode * root = new TreeNode(root_val);
        int idx = lo + 1;
        for(; idx < hi; ++idx) {
            if(preorder[idx] > root_val) break;
        }
        // cout << idx << endl;
        root->left = helper(preorder, lo + 1, idx);
        root->right = helper(preorder, idx, hi);
        return root;
    }
};
