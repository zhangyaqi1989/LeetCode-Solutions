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
    bool isCousins(TreeNode* root, int x, int y) {
        map<int, int> parents;
        map<int, int> depths;
        traverse(root, -1, 0, parents, depths);
        return parents[x] != parents[y] && depths[x] == depths[y];
    }
    
    void traverse(TreeNode * node, int parent, int depth, map<int, int> & parents, map<int, int> & depths) {
        if (node != nullptr) {
            parents[node->val] = parent;
            depths[node->val] = depth;
            traverse(node->left, node->val, depth + 1, parents, depths);
            traverse(node->right, node->val, depth + 1, parents, depths);
        }
    }
    
    
};
