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
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode * second = head->next;
        ListNode * new_head = reverseList(head->next);
        second->next = head;
        head->next = nullptr;
        return new_head;
    }
};
