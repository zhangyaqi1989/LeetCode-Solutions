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
    int pathSum(TreeNode* root, int sum) {
        unordered_map<int, int> seen;
        seen[0] = 1;
        int ans = 0;
        Dfs(root, sum, 0, & ans, & seen);
        return ans;
    }
    
private:
    void Dfs(TreeNode * node, int sum, int acc, int * ans, unordered_map<int, int> * seen) {
        if(node != nullptr) {
            acc += node->val;
            int need = acc - sum;
            auto it = seen->find(need);
            if(it != seen->end()) {
                (*ans) += it->second;
            }
            (*seen)[acc]++;
            Dfs(node->left, sum, acc, ans, seen);
            Dfs(node->right, sum, acc, ans, seen);
            (*seen)[acc]--;
        }
    }
};
