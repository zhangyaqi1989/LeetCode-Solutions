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
    int distributeCoins(TreeNode* root) {
        int cnt = 0;
        post(root, cnt);
        return cnt;
    }
    
    int post(TreeNode * node, int & cnt) {
        if (node != nullptr) {
            int lc = post(node->left, cnt), rc = post(node->right, cnt);
            cnt += abs(lc) + abs(rc);
            return node->val - 1 + lc + rc;
        }
        return 0;
    }
    
    
};
