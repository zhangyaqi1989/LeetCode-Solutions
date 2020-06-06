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
        vector<vector<TreeNode*>> trees(N + 1);
        trees[0].push_back(nullptr);
        trees[1].push_back(new TreeNode(0));
        for(int i = 3; i <= N; i += 2) {
            for(int j = 1; j < i; j += 2) {
                for(auto left : trees[j]) {
                    for(auto right : trees[i - 1 - j]) {
                        TreeNode * root = new TreeNode(0);
                        root->left = left;
                        root->right = right;
                        trees[i].push_back(root);
                    }
                }
            }
        }
        return trees.back();
    }
};
