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
    ListNode* plusOne(ListNode* head) {
        ListNode dummy = ListNode(0);
        dummy.next = head;
        ListNode * cur = & dummy;
        while (head != nullptr) {
            if (head->val != 9) cur = head;
            head = head->next;
        }
        if (cur == &dummy) {
            ListNode * new_head = new ListNode(0);
            new_head->next = cur->next;
            cur->next = new_head;
            cur = new_head;
        }
        cur->val += 1;
        cur = cur->next;
        while (cur != nullptr) {
            cur->val = 0;
            cur = cur->next;
        }
        return dummy.next;
    }
};
