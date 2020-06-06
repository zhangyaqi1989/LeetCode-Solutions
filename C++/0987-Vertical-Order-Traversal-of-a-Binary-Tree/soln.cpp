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
        map<int, vector<pair<int, int>>> counter;
        helper(root, counter, 0, 0);
        vector<vector<int>> ans;
        int level = 0;
        for(auto & col : counter) {
            vector<pair<int, int>> & lst = col.second;
            sort(lst.begin(), lst.end());
            vector<int> temp;
            for (auto & p : lst) {
                temp.push_back(p.second);
            }
            ans.push_back(temp);
        }
        return ans;
    }
    
    void helper(TreeNode * node, map<int, vector<pair<int, int>>> & counter, int x, int y) {
        if(node) {
            counter[x].push_back(make_pair(y, node->val));
            if (node->left) helper(node->left, counter, x - 1, y + 1);
            if (node->right) helper(node->right, counter, x + 1, y + 1);
        }
    }
};
