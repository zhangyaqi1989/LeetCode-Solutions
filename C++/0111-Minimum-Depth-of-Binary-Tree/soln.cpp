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
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        int depth = 0;
        deque<TreeNode*> q;
        q.push_back(root);
        while (q.size()) {
            ++depth;
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                TreeNode * node = q.front();
                q.pop_front();
                if (!node->left && !node->right) return depth;
                if (node->left) q.push_back(node->left);
                if (node->right) q.push_back(node->right);
            }
        }
    }
};