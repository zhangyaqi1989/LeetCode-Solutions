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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == nullptr) return ans;
        queue<TreeNode *> q;
        q.push(root);
        bool reversed = false;
        while(! q.empty())
        {
            int size = q.size();
            vector<int> vals;
            for(auto i = 0; i < size; ++i)
            {
                TreeNode * node = q.front();
                q.pop();
                vals.push_back(node->val);
                if (node->left != nullptr) q.push(node->left);
                if (node->right != nullptr) q.push(node->right);
            }
            if(reversed) reverse(vals.begin(), vals.end());
            ans.push_back(vals);
            reversed = !reversed;
        }
        return ans;
    }
};