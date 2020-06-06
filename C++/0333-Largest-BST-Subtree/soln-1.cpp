/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct Record {
    long mn;
    long mx;
    int nnodes;
    bool isBST;
    Record(long mn, long mx, int nnodes, bool isBST): mn(mn), mx(mx), nnodes(nnodes), isBST(isBST) {}
};
class Solution {
public:
    int largestBSTSubtree(TreeNode* root) {
        int ans = 0;
        Postorder(root, & ans);
        return ans;
    }
    
private:
    Record Postorder(TreeNode * root, int * ans) {
        if (root == nullptr) return Record(LONG_MAX, LONG_MIN, 0, true);
        Record left_record = Postorder(root->left, ans);
        Record right_record = Postorder(root->right, ans);
        long mn = min((long) root->val, min(left_record.mn, right_record.mn));
        long mx = max((long) root->val, max(left_record.mx, right_record.mx));
        int nnodes = 1 + left_record.nnodes + right_record.nnodes;
        bool isBST = false;
        if (left_record.isBST && right_record.isBST && root->val > left_record.mx && root->val < right_record.mn) {
            isBST = true;
            *ans = max(*ans, nnodes);
        }
        return Record(mn, mx, nnodes, isBST);
    }
};
