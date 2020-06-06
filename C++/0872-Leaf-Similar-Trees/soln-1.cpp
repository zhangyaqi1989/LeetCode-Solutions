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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        stack<TreeNode *> s1, s2;
        s1.push(root1);
        s2.push(root2);
        while (!s1.empty() && !s2.empty()) {
            int val1 = dfs(s1);
            int val2 = dfs(s2);
            if (val1 != val2) return false;
        }
        return s1.empty() && s2.empty();
    }
    
    int dfs(stack<TreeNode *> & s) {
        while(true) {
            TreeNode * node = s.top();
            s.pop();
            if (node->right != nullptr) s.push(node->right);
            if (node->left != nullptr) s.push(node->left);
            if (node->left == nullptr && node->right == nullptr) return node->val;
        }
    }
    
    
};
