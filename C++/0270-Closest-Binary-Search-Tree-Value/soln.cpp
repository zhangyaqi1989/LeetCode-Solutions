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
    int closestValue(TreeNode* root, double target) {
        auto ans = helper(root, target);
        return ans.second;
    }
    
    pair<double, int> helper(TreeNode * node, double target) {
        if (node == nullptr) return {DBL_MAX, 0};
        if (target > node->val) {
            auto temp = helper(node->right, target);
            if (temp.first < target - node->val) {
                return temp;
            } else {
                return {target - node->val, node->val};
            }
        } else {
            auto temp = helper(node->left, target);
            if (temp.first < node->val - target) {
                return temp;
            } else {
                return {node->val - target, node->val};
            }
        }
    } 
};
