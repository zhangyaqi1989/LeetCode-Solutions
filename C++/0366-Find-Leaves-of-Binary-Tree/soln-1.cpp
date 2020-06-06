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
    vector<vector<int>> findLeaves(TreeNode* root) {
        map<TreeNode *, TreeNode*> parents;
        map<TreeNode *, int> nchildren;
        vector<TreeNode *> leaves;
        dfs(root, parents, nchildren, leaves);
        vector<vector<int>> ans;
        while (!leaves.empty()) {
            vector<TreeNode *> temp;
            vector<int> level;
            for(auto node : leaves) {
                level.push_back(node->val);
                if (--nchildren[parents[node]] == 0)
                    temp.push_back(parents[node]);
            }
            swap(temp, leaves);
            ans.push_back(level);
        }
        return ans;
    }
    
    void dfs(TreeNode * node, map<TreeNode *, TreeNode*> & parents, map<TreeNode *, int> & nchildren, vector<TreeNode *> & leaves) {
        if (node != nullptr) {
            if (node->left == nullptr && node->right == nullptr) {
                leaves.push_back(node);
            } else {
                if (node->left != nullptr) {
                    parents[node->left] = node;
                    nchildren[node] ++;
                    dfs(node->left, parents, nchildren, leaves);
                }
                if (node->right != nullptr) {
                    parents[node->right] = node;
                    nchildren[node] ++;
                    dfs(node->right, parents, nchildren, leaves);
                }
            }
        }
    }
};
