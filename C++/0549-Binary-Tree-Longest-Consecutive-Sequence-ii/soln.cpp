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
    int longestConsecutive(TreeNode* root) {
        int ans = 0;
        postorder(root, ans);
        return ans;
    }
    
    vector<int> postorder(TreeNode* node, int & ans) {
        if (node != nullptr) {
            auto l = postorder(node->left, ans);
            auto r = postorder(node->right, ans);
            int l_inc = l[0], l_dec = l[1], r_inc = r[0], r_dec = r[1];
            int inc = 1, dec = 1;
            if (node->left != nullptr) {
                if (node->val + 1 == node->left->val) {
                    inc = max(inc, l_inc + 1);
                } else if (node->val - 1 == node->left->val) {
                    dec = max(dec, l_dec + 1);
                }
            }
            if (node->right != nullptr) {
                if (node->val + 1 == node->right->val) {
                    inc = max(inc, r_inc + 1);
                } else if (node->val - 1 == node->right->val) {
                    dec = max(dec, r_dec + 1);
                }
            }
            ans = max(ans, inc + dec - 1);
            return {inc, dec};
        } else {
            return {0, 0};
        }
    }
};
