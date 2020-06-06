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
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) 
            return head;
        ListNode * rest = swapPairs(head->next->next);
        ListNode * new_head = head->next;
        new_head->next = head;
        head->next = rest;
        return new_head;
    }
};
