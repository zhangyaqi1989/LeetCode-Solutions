/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    double maximumAverageSubtree(TreeNode* root) {
        double max_avg = 0.0;
        Postorder(root, & max_avg);
        return max_avg;
    }
    
private:
    pair<double, int> Postorder(TreeNode * node, double * max_avg) {
        if(node != nullptr) {
            auto [left_sum, left_cnt] = Postorder(node->left, max_avg);
            auto [right_sum, right_cnt] = Postorder(node->right, max_avg);
            double sum = left_sum + right_sum + node->val;
            int cnt = left_cnt + right_cnt + 1;
            *max_avg = max(*max_avg, sum / cnt);
            return {sum, cnt};
        }
        return {0.0, 0};
    }
};
