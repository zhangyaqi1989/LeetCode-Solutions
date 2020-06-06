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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> deletes(to_delete.begin(), to_delete.end());
        unordered_map<TreeNode *, TreeNode*> parents;
        dfs(root, nullptr, true, deletes, parents);
        vector<TreeNode *> ans;
        for (auto & p : parents) {
            if (!deletes.count(p.first->val) && p.second == nullptr) {
                ans.push_back(p.first);
            }
        }
        return ans;
    }
    
private:
    void dfs(TreeNode * node, TreeNode * parent, bool is_left,
             const unordered_set<int> & deletes, 
             unordered_map<TreeNode *, TreeNode *> & parents) {
        if (node != nullptr) {
            parents[node] = parent;
            // record parent
            if (parent != nullptr && deletes.count(parent->val)) {
                parents[node] = nullptr;
            }
            // set nullptr
            if (deletes.count(node->val)) {
                if (parent != nullptr) {
                    if (is_left) parent->left = nullptr;
                    else parent->right = nullptr;
                }
            }
            dfs(node->left, node, true, deletes, parents);
            dfs(node->right, node, false, deletes, parents);
        }
    }
};
