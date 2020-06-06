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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode * dummy = new ListNode(-1);
        dummy->next = head;
        ListNode * cur = dummy;
        while(cur && cur->next) {
            if (cur->next->val == val) {
                cur->next = cur->next == nullptr ? nullptr : cur->next->next;
            } else {
                cur = cur->next;
            }
        }
        return dummy->next;
    }
};
