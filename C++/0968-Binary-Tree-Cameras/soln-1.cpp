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
        int cnt = 0;
        return (dfs(root, cnt) == NO_COVERED) + cnt;
    }
    
private:
    int dfs(TreeNode * root, int & cnt) {
        if (root == nullptr) return COVERED;
        if(root->left == nullptr && root->right == nullptr) return NO_COVERED;
        int left = dfs(root->left, cnt);
        int right = dfs(root->right, cnt);
        if (left == NO_COVERED || right == NO_COVERED) {
            ++cnt;
            return HAS_CAMERA;
        }
        return left == HAS_CAMERA || right == HAS_CAMERA ? COVERED : NO_COVERED;
    }
    static const int NO_COVERED = 0, COVERED = 1, HAS_CAMERA = 2;
};
