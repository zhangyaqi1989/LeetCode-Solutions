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
    int findSecondMinimumValue(TreeNode* root) {
        int first = INT_MAX, second = INT_MAX;
        traverse(root, first, second);
        // cout << first << " " << second << endl;
        return second != INT_MAX ? second : -1;
    }
    
    void traverse(TreeNode * node, int & first, int & second) {
        if (node != nullptr) {
            // do something
            if (node->val < first) {
                first = node->val;
            } else if (node->val != first && node->val < second) {
                second = node->val;
            }
            traverse(node->left, first, second);
            traverse(node->right, first, second);
        }
    }
};
