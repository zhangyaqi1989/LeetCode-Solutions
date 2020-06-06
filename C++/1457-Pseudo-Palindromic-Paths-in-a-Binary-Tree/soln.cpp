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
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> counter(10, 0);
        int ans = 0;
        Dfs(root, &counter, &ans);
        return ans;
    }
    
private:
    void Dfs(TreeNode * node, vector<int> * counter, int * ans) {
        if(node != nullptr) {
            ++(*counter)[node->val];
            if(node->left == nullptr && node->right == nullptr) {
                if(count_if(counter->begin() + 1, counter->end(), [](int x) {return x % 2;}) <= 1) {
                    ++(*ans);
                }
            }
            Dfs(node->left, counter, ans);
            Dfs(node->right, counter, ans);
            --(*counter)[node->val];
        }
    }
};
