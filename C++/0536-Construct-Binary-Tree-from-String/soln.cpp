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
    TreeNode* str2tree(string s) {
        int i = 0;
        return s.length() == 0 ? nullptr : build(s, i);
    }
    
    TreeNode * build(string & s, int & i) {
        int start = i;
        while (i < s.length() && s[i] != '(' && s[i] != ')') ++i;
        int val = stoi(s.substr(start, i - start));
        TreeNode * root = new TreeNode(val);
        if (i < s.length() && s[i] == '(') {
            root->left = build(s, ++i);
            i += 1;
        }
        if (i < s.length() && s[i] == '(') {
            root->right = build(s, ++i);
            i += 1;
        }
        return root;
    }
};
