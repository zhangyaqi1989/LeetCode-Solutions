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
    int minCameraCover(TreeNode* root) {
        // 0: not coverd
        // 1: covered, without camera on it
        // 2: covered, with camera on it
        int ans = 0;
        if (postorder(root, ans) == 0) {
            ++ans;
        }
        return ans;
    }
    
    int postorder(TreeNode * node, int & ans) {
        if (node != nullptr) {
            int l = postorder(node->left, ans);
            int r = postorder(node->right, ans);
            if (l == 0 || r == 0) {
                ++ans;
                return 2;
            } else if (l == 2 || r == 2) {
                return 1;
            } else {
                return 0;
            }
        } else {
            return 1;
        }
    }
};
