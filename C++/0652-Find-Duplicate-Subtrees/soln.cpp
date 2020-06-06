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
    map<string, vector<TreeNode*>> subs;
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        subs.clear();
        helper(root);
        vector<TreeNode*> ans;
        for(auto & it : subs) {
            if (it.second.size() > 1) ans.push_back(it.second[0]);
        }
        return ans;
    }
    
    string helper(TreeNode * node) {
        if (node == nullptr) return "#";
        string ans = to_string(node->val) + helper(node->left) +helper(node->right);
        subs[ans].push_back(node);
        return ans;
    }
};
