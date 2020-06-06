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
        stack<pair<TreeNode *, int>> stk;
        int cnt = 0;
        int n = S.length();
        int pre = -1;
        TreeNode * root = nullptr;
        for(int i = 0; i < n; ++i) {
            char ch = S[i];
            if (ch == '-') ++cnt;
            else {
                int num = 0;
                while (i < n && isdigit(S[i])) {
                    num = num * 10 + S[i] - '0';
                    ++i;
                }
                --i;
                TreeNode * node = new TreeNode(num);
                if (cnt == 0) root = node;
                if (cnt > pre) {
                    if (!stk.empty()) {
                        stk.top().first->left = node;
                    }
                    stk.push({node, cnt});
                } else {
                    while(!stk.empty() && stk.top().second >= cnt) {
                        stk.pop();
                    }
                    stk.top().first->right = node;
                    stk.push({node, cnt});
                }
                pre = cnt;
                cnt = 0;
            }
        }
        return root;
    }
};
