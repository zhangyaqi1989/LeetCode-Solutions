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
    ListNode* sortList(ListNode* head) {
        // use merge sort
        // sort left and right, and merge
        if (head == nullptr || head->next == nullptr) return head;
        int cnt = 0;
        ListNode * slow = head;
        while(slow != nullptr) {
            ++cnt;
            slow = slow->next;
        }
        slow = head;
        for(int i = 0; i < cnt / 2 - 1; ++i) slow = slow->next;
        ListNode * right = slow->next;
        slow->next = nullptr;
        right = sortList(right);
        ListNode * left = sortList(head);
        ListNode * dummy = new ListNode(-1);
        ListNode * cur = dummy;
        while(left != nullptr && right != nullptr) {
            if (left->val < right->val) {
                cur->next = left;
                left = left->next;
            } else {
                cur->next = right;
                right = right->next;
            }
            cur = cur->next;
        }
        if(left == nullptr) cur->next = right;
        else cur->next = left;
        return dummy->next;
    }
};
