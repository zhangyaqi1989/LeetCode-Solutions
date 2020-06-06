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
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        return build(pre, post, 0, pre.size(), 0, post.size());
    }
    
    TreeNode* build(vector<int> & pre, vector<int> & post, int pre_lo, int pre_hi, int post_lo, int post_hi) {
        if (pre_lo >= pre_hi) return nullptr;
        TreeNode * root = new TreeNode(pre[pre_lo]);
        set<int> seen;
        bool find_split = false;
        for(int idx = pre_lo + 1; idx < pre_hi; ++idx) {
            if(seen.find(pre[idx]) == seen.end()) {
                seen.insert(pre[idx]);
            } else {
                seen.erase(pre[idx]);
            }
            if (seen.find(post[post_lo + idx - pre_lo - 1]) == seen.end()) {
                seen.insert(post[post_lo + idx - pre_lo - 1]);
            } else {
                seen.erase(post[post_lo + idx - pre_lo - 1]);
            }
            if (seen.size() == 0) {
                root->left = build(pre, post, pre_lo + 1, idx + 1, post_lo, post_lo + idx - pre_lo);
                root->right = build(pre, post, idx + 1, pre_hi, post_lo + idx - pre_lo, post_hi - 1);
                break;
            }
        }
        return root;
    }
};
