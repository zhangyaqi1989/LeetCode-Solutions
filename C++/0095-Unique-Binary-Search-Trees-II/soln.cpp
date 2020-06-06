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
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0) return {};
        return build(1, n + 1);
    }
    
    vector<TreeNode *> build(int l, int r)
    {
        if (l >= r) return {nullptr};
        if (l == r - 1) return {new TreeNode(l)};
        vector<TreeNode *> ans;
        for(int i = l; i < r; ++i)
        {
            for(auto left : build(l, i))
                for(auto right: build(i + 1, r))
                {
                    TreeNode * root = new TreeNode(i);
                    root -> left = left;
                    root -> right = right;
                    ans.push_back(root);
                }
        }
        return ans;
    }
};