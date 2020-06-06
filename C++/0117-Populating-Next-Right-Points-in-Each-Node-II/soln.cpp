/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *node) {
        TreeLinkNode * dummy = new TreeLinkNode(0);
        TreeLinkNode * tail = dummy;
        while (node) {
            tail->next = node->left;
            if (tail->next) tail = tail->next;
            tail->next= node->right;
            if (tail->next) tail = tail->next;
            node = node->next;
            if (!node) {
                tail = dummy;
                node = dummy->next;
            }
        }
        delete dummy;
    }
};
