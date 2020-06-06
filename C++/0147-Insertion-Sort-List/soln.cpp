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
    ListNode* insertionSortList(ListNode* head) {
        ListNode * dummy = new ListNode(INT_MIN);
        while (head != nullptr) {
            ListNode * cur = dummy;
            while (cur->next != nullptr && cur->next->val < head->val) cur = cur->next;
            ListNode * nxt = head->next;
            head->next = cur->next;
            cur->next = head;
            head = nxt;
        } 
        return dummy->next;
    }
};
