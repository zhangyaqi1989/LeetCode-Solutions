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
    bool isCompleteTree(TreeNode* root) {
        queue<pair<TreeNode *, int>> q;
        q.push({root, 1});
        int cnt = 1;
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            auto node = p.first;
            int idx = p.second;
            if (idx != cnt) return false;
            if (node->left != nullptr)
                q.push({node->left, 2 * idx});
            if (node->right != nullptr)
                q.push({node->right, 2 * idx + 1});
            ++cnt;
        }
        return true;
    }
};
