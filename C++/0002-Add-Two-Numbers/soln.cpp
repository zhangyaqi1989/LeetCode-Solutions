/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// ALG
// 1. use carry to add
auto desyncio = []()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;
        int carry = 0;
        while(l1 || l2 || carry) {
            int val1 = l1 ? l1->val : 0;
            int val2 = l2 ? l2->val : 0;
            int val = val1 + val2 + carry;
            ListNode * node = new ListNode(val % 10);
            carry = val / 10;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
            cur->next = node;
            cur = cur->next;
        }
        return dummy->next;
    }
};
