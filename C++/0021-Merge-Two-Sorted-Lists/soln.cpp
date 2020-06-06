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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode * p1 = l1;
        ListNode * p2 = l2;
        ListNode * cur = new ListNode(0);
        ListNode * head = cur;
        while (p1 != nullptr && p2 != nullptr)
        {
            if (p1 -> val <= p2 -> val)
            {
                cur->next = p1;
                p1 = p1->next;
            } else
            {
                cur->next = p2;
                p2 = p2->next;
            }
            cur = cur->next;
        }
        cur->next = p1 == nullptr ? p2 : p1;
        return head->next;
    }
};