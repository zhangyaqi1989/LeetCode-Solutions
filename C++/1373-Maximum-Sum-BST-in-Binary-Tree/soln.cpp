/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

const int kInf = 1e9 + 7;

struct Record {
    bool is_bst;
    int mn;
    int mx;
    int sum;
};

class Solution {
public:
    int maxSumBST(TreeNode* root) {
        int ans = 0;
        Postorder(root, & ans);
        return ans;
    }
    
private:
    Record Postorder(TreeNode * root, int * ans) {
        if (root == nullptr) return {true, kInf, -kInf, 0};
        Record left = Postorder(root->left, ans);
        Record right = Postorder(root->right, ans);
        bool is_bst = false;
        int mn = min(root->val, min(left.mn, right.mn));
        int mx = max(root->val, max(left.mx, right.mx));
        int sum = root->val + left.sum + right.sum;
        if (left.is_bst && right.is_bst && left.mx < root->val && root->val < right.mn) {
            *ans = max(*ans, sum);
            is_bst = true;
        }
        return {is_bst, mn, mx, sum};
    }
};
