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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        // map: key (hash function of this tree) : vector of roots
        // encode this tree a string
        // how to represent a tree using string
        // root left right
        // left root right
        unordered_map<string, vector<TreeNode *>> memo;
        Postorder(root, &memo);
        vector<TreeNode *> ans;
        for(const auto & p : memo) {
            if (p.second.size() > 1) {
                ans.push_back(p.second[0]);
            }
        }
        return ans;
    }
    
private:
    string Postorder(TreeNode * node, unordered_map<string, vector<TreeNode *>> * memo) {
        if (node != nullptr) {
            string l = Postorder(node->left, memo);
            string r = Postorder(node->right, memo);
            string hash = to_string(node->val) + l + r;
            (*memo)[hash].push_back(node);
            return hash;
        } else {
            return "#";
        }
    }
};
