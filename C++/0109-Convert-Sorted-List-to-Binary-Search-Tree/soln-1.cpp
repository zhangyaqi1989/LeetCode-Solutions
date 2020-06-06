/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> vals;
        while (head != nullptr) {
            vals.push_back(head->val);
            head = head->next;
        }
        const int kN = vals.size();
        return BuildTree(vals, 0, kN - 1);
    }
    
private:
    TreeNode * BuildTree(const vector<int> & vals, int lo, int hi) {
        if (lo > hi) return nullptr;
        int mid = lo + (hi - lo) / 2;
        TreeNode * root = new TreeNode(vals[mid]);
        root->left = BuildTree(vals, lo, mid - 1);
        root->right = BuildTree(vals, mid + 1, hi);
        return root;
    }
};
