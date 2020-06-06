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
        stack<int> s1, s2;
        for(; l1; l1 = l1->next) s1.push(l1->val);
        for(; l2; l2 = l2->next) s2.push(l2->val);
        ListNode * head = nullptr;
        int carry = 0;
        while (!s1.empty() || !s2.empty() || carry != 0) {
            int v1 = 0, v2 = 0;
            if (!s1.empty()) {
                v1 = s1.top();
                s1.pop();
            }
            if (!s2.empty()) {
                v2 = s2.top();
                s2.pop();
            }
            int v = v1 + v2 + carry;
            carry = v / 10;
            ListNode * node = new ListNode(v % 10);
            node->next = head;
            head = node;
        }
        return head;
    }
};
