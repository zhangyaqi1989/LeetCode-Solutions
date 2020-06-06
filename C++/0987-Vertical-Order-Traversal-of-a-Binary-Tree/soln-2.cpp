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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<pair<int, int>>> nodes;
        dfs(root, 0, 0, nodes);
        vector<vector<int>> ans((int) nodes.size());
        int i = 0;
        for(auto & p : nodes) {
            sort(p.second.begin(), p.second.end());
            for(auto & item : p.second) {
                ans[i].push_back(item.second);
            }
            ++i;
        }
        return ans;
    }
    
private:
    void dfs(TreeNode * root, int X, int Y, map<int, vector<pair<int, int>>> & nodes) {
        if (root != nullptr) {
            nodes[X].emplace_back(Y, root->val);
            dfs(root->left, X - 1, Y + 1, nodes);
            dfs(root->right, X + 1, Y + 1, nodes);
        }
    }
};
