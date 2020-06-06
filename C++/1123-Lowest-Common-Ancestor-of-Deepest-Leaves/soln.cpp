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
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int l = getDepth(root->left);
        int r = getDepth(root->right);
        if (l == r) return root;
        else if (l > r) return lcaDeepestLeaves(root->left);
        else return lcaDeepestLeaves(root->right);
    }
    
    int getDepth(TreeNode * node) {
        auto it = depths.find(node);
        if (it != depths.end()) return it->second;
        int ans = 0;
        if (node != nullptr) {
            int l = getDepth(node->left);
            int r = getDepth(node->right);
            ans = max(l, r) + 1;            
        }
        depths[node] = ans;
        return ans;
    }

private:
    unordered_map<TreeNode *, int> depths;
};
