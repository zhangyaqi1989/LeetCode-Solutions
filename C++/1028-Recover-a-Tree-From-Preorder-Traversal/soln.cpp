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
    TreeNode* recoverFromPreorder(string S) {
        int pre = -1;
        vector<pair<TreeNode *, int>> stk;
        TreeNode * root = nullptr;
        int lo = 0, n = S.length();
        while (lo < n) {
            int depth = 0;
            while (lo < n && S[lo] == '-') {
                ++depth;
                ++lo;
            }
            int val = 0;
            while (lo < n && isdigit(S[lo])) {
                val = val * 10 + S[lo] - '0';
                ++lo;
            }
            // cout << depth << " " << val << endl;
            TreeNode * node = new TreeNode(val);
            if (root == nullptr) {
                root = node;
            }
            if (depth > pre) {
                if (!stk.empty()) stk.back().first->left = node;
            } else if (depth == pre) {
                stk[stk.size() - 2].first->right = node;
                // cout << stk[stk.size() - 2].first->val << "right" << node->val << endl;
            } else {
                while (!stk.empty() && stk.back().second >= depth) {
                    stk.pop_back();
                }
                stk.back().first->right = node;
            }
            stk.emplace_back(node, depth);
            pre = depth;
        }
        return root;
    }
};
