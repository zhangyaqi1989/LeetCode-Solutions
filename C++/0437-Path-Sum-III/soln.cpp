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
    int ans;
public:
    int pathSum(TreeNode* root, int sum) {
        ans = 0;
        unordered_map<int, int> counter;
        counter[0] = 1;
        dfs(root, counter, 0, sum);
        return ans;
    }
    
    void dfs(TreeNode * node, unordered_map<int, int> & counter,  int acc, int sum) {
        if (node != nullptr) {
            acc += node->val;
            auto it = counter.find(acc - sum);
            if (it != counter.end()) {
                ans += it->second;
            }
            ++counter[acc];
            dfs(node->left, counter, acc, sum);
            dfs(node->right, counter, acc, sum);
            --counter[acc];
        }
    }
    
    
};
