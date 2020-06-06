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
    bool checkEqualTree(TreeNode* root) {
        unordered_set<int> subs;
        int sum = Postorder(root, nullptr, & subs);
        return sum % 2 == 0 && subs.find(sum / 2) != subs.end();
    }
    
private:
    int Postorder(TreeNode * root, TreeNode * parent, unordered_set<int> * subs) {
        if (root == nullptr) return 0;
        int l = Postorder(root->left, root, subs);
        int r = Postorder(root->right, root, subs);
        int total = l + r + root->val;
        if (parent != nullptr) {
            subs->insert(total);
        }
        return total;
    }
};
