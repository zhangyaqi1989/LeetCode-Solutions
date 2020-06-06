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
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        // need to know the number of nodes in its subtree
        vector<int> nodes_in_subtree(n + 1);
        vector<int> max_child_nodes(n + 1);
        dfs(root, & nodes_in_subtree, & max_child_nodes);
        return max(n - nodes_in_subtree[x], max_child_nodes[x]) > n / 2;
    }
    
private:
    int dfs(TreeNode * root, vector<int> * nodes_in_subtree, vector<int> * max_child_nodes) {
        if (root != nullptr) {
            int l = dfs(root->left, nodes_in_subtree, max_child_nodes);
            int r = dfs(root->right, nodes_in_subtree, max_child_nodes);
            (*max_child_nodes)[root->val] = max(l, r);
            (*nodes_in_subtree)[root->val] = l + r + 1;
            return l + r + 1;
        }
        return 0;
    }
};
