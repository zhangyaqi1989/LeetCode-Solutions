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
        return buildTree(pre, post, 0, (int) pre.size() - 1, 0, (int) post.size() - 1);
    }
    
private:
    TreeNode * buildTree(const vector<int> & pre, const vector<int> & post,
                         int lo_pre, int hi_pre, int lo_post, int hi_post) {
        if (lo_pre == hi_pre) {
            return new TreeNode(pre[lo_pre]);
        } else if (lo_pre > hi_pre) {
            return nullptr;
        } else {
            unordered_map<int, int> window;
            TreeNode * root = new TreeNode(pre[lo_pre]);
            for(int i = lo_pre + 1; i <= hi_pre; ++i) {
                auto pre_it = window.find(pre[i]);
                if(pre_it == window.end()) {
                    ++window[pre[i]];
                } else {
                    if(--pre_it->second == 0) window.erase(pre_it);
                }
                auto post_it = window.find(post[lo_post + i - lo_pre - 1]);
                if(post_it == window.end()) {
                    ++window[post[lo_post + i - lo_pre - 1]];
                } else {
                    if (--post_it->second == 0) window.erase(post_it);
                }
                if (window.empty()) {
                    int cnt = i - lo_pre;
                    root->left = buildTree(pre, post, lo_pre + 1, lo_pre + cnt, lo_post, lo_post + cnt - 1);
                    root->right = buildTree(pre, post, lo_pre + cnt + 1, hi_pre, lo_post + cnt, hi_post - 1);
                    break;
                }
            }
            return root;
        }
    }
};
