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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse(l1);
        l2 = reverse(l2);
        ListNode * dummy = new ListNode(0);
        ListNode * cur = dummy;
        int carry = 0;
        while (l1 || l2 || carry) {
            int val1 = l1 == nullptr ? 0 : l1->val;
            int val2 = l2 == nullptr ? 0 : l2->val;
            int val = val1 + val2 + carry;
            carry = val / 10;
            ListNode * node = new ListNode(val % 10);
            cur->next = node;
            cur = cur->next;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        return reverse(dummy->next);
    }
    
    ListNode* reverse(ListNode * head) {
        ListNode * pre = nullptr;
        ListNode * cur = head;
        while (cur != nullptr) {
            ListNode * nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
        return pre;
    }
};
