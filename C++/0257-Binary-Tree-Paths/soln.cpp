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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        traverse(root, "", ans);
        return ans;
    }
    
    void traverse(TreeNode * node, string path, vector<string> & ans)
    {
        if(node != nullptr)
        {
            if(node->left == nullptr && node->right == nullptr)
                ans.push_back(path + to_string(node->val));
            else
            {
                traverse(node->left, path + to_string(node->val) + "->", ans);
                traverse(node->right, path + to_string(node->val) + "->", ans);
            }
        }
    }
};