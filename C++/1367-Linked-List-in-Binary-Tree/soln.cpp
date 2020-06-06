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
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (root == nullptr) return head == nullptr;
        return helper(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);
    }
    
private:
    bool helper(ListNode * cur, TreeNode * node) {
        if (cur == nullptr) return true;
        if (node == nullptr) return false;
        return cur->val == node->val && (helper(cur->next, node->left) || helper(cur->next, node->right));
    }
};
