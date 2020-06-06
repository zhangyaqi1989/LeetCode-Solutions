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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        if (K == 0) return {target->val};
        unordered_map<TreeNode *, vector<TreeNode*>> tree;
        traverse(root, tree);
        vector<int> ans;
        queue<pair<TreeNode *, TreeNode *>> frontier;
        frontier.emplace(target, nullptr);
        while (K > 0 && !frontier.empty()) {
            int sz = frontier.size();
            for(int i = 0; i < sz; ++i) {
                TreeNode * node;
                TreeNode * parent;
                tie(node, parent) = frontier.front();
                // cout << node->val << endl;
                frontier.pop();
                for(TreeNode * nei : tree[node]) {
                    if (nei != parent) frontier.emplace(nei, node);
                }
            }   
            --K;
        }
        while (!frontier.empty()) {
            ans.push_back(frontier.front().first->val);
            frontier.pop();
        }
        return ans;
    }
    
    void traverse(TreeNode * node, unordered_map<TreeNode *, vector<TreeNode*>>& tree) {
        if (node != nullptr) {
            if (node->left != nullptr) {
                tree[node].push_back(node->left);
                tree[node->left].push_back(node);
                traverse(node->left, tree);
            }
            if (node->right != nullptr) {
                tree[node].push_back(node->right);
                tree[node->right].push_back(node);
                traverse(node->right, tree);
            }
        }
    }
};
