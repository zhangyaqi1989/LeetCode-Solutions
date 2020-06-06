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
    vector<TreeNode*> allPossibleFBT(int N) {
        vector<TreeNode *> ans;
        if (N == 1) ans.push_back(new TreeNode(0));
        else {
            for(int left = 1; left < N - 1; left += 2) {
                int right = N - left - 1;
                vector<TreeNode *> left_nodes = allPossibleFBT(left);
                vector<TreeNode *> right_nodes = allPossibleFBT(right);
                for(auto left : left_nodes) {
                    for(auto right : right_nodes) {
                        TreeNode * root = new TreeNode(0);
                        root->left = left;
                        root->right = right;
                        ans.push_back(root);
                    }
                }
            }
        }
        return ans;        
    }

};
