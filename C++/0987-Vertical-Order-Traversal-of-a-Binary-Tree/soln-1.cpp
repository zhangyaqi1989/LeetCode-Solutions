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
        // map X to (Y, value) pair list
        map<int, vector<pair<int, int>>> m;
        traverse(0, 0, root, m);
        vector<vector<int>> ans;
        ans.resize(m.size());
        int idx = 0;
        for(auto & p : m) {
            vector<pair<int, int>> & lst = p.second;
            sort(lst.begin(), lst.end());
            for(auto & item : lst) {
                // cout << item.second << endl;
                ans[idx].push_back(item.second);
            }
            ++idx;
        }
        return ans;
    }
    
    void traverse(int X, int Y, TreeNode * node, map<int, vector<pair<int, int>>> & m) {
        if (node != nullptr) {
            // cout << Y << " " << node->val << endl;
            m[X].push_back({-Y, node->val});
            traverse(X - 1, Y - 1, node->left, m);
            traverse(X + 1, Y - 1, node->right, m);
        }
    }
};
