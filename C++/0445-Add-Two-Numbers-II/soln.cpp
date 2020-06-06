/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

auto desyncio = []()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

// ALG:
// 1. reverse the list
// 2. add the list

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverseNode(l1);
        l2 = reverseNode(l2);
        ListNode* dummy = new ListNode(1);
        ListNode* cur = dummy;
        int carry = 0;
        while(l1 || l2 || carry) {
            int val1 = l1 ? l1->val : 0;
            int val2 = l2 ? l2->val : 0;
            int val = val1 + val2 + carry;
            carry = val / 10;
            ListNode* newNode = new ListNode(val % 10);
            cur->next = newNode;
            cur = cur->next;
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
        }
        return reverseNode(dummy->next);
    }
    
    ListNode* reverseNode(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while(cur) {
            ListNode* nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
        return pre;
    }
};
