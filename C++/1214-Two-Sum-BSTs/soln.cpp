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
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        vector<int> vals1, vals2;
        Dfs(root1, &vals1);
        Dfs(root2, &vals2);
        sort(vals2.begin(), vals2.end());
        for(int val : vals1) {
            auto it = lower_bound(vals2.begin(), vals2.end(), target - val);
            if(it != vals2.end() && *it == target - val) {
                return true;
            }
        }
        return false;
    }
    
private:
    void Dfs(TreeNode * node, vector<int> * vals) {
        if(node != nullptr) {
            vals->push_back(node->val);
            Dfs(node->left, vals);
            Dfs(node->right, vals);
        }
    }
};
