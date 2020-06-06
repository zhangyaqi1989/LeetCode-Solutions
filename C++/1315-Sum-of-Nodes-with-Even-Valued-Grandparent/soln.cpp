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
    int sumEvenGrandparent(TreeNode* root) {
        int sum = 0;
        Dfs(root, nullptr, nullptr, &sum);
        return sum;
    }
    
private:
    void Dfs(TreeNode * node, TreeNode * parent, TreeNode * grandparent, int * sum) {
        if (node != nullptr) {
            if (grandparent != nullptr && grandparent->val % 2 == 0) *sum += node->val;
            Dfs(node->left, node, parent, sum);
            Dfs(node->right, node, parent, sum);
        }
    }
};
