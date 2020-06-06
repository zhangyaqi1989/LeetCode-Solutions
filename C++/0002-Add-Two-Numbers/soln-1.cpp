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
        int carry = 0;
        ListNode dummy = ListNode(0);
        ListNode * cur = & dummy;
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int v1 = l1 != nullptr ? l1->val : 0;
            int v2 = l2 != nullptr ? l2->val : 0;
            // cout << v1 << " " << v2 << endl;
            int v = v1 + v2 + carry;
            int d = v % 10;
            carry = v / 10;
            cur->next = new ListNode(d);
            cur = cur->next;
            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
        }
        return dummy.next;
    }
};
