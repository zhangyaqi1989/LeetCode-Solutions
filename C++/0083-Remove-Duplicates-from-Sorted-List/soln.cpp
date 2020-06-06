/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode * cur = head;
        ListNode * pre;
        while (cur) {
            pre = cur;
            while(cur && pre->val == cur->val) {
                cur = cur->next;
            }
            pre->next = cur;
        }
        return head;
    }
};
