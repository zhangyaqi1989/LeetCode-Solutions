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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ans;
        vector<int> path;
        helper(root, path, sum, ans);
        return ans;
    }
    
    void helper(TreeNode * node, vector<int>& path, int target, vector<vector<int>> & ans)
    {
        if (node != nullptr)
        {
            if(node->left == nullptr && node->right == nullptr)
            {
                if(target == node->val)
                {
                    path.push_back(node->val);
                    ans.push_back(path);
                    path.pop_back();
                }
            } else
            {
                path.push_back(node->val);
                helper(node->left, path, target - node->val, ans);
                helper(node->right, path, target - node->val, ans);
                path.pop_back();
            }
        }
    }
};