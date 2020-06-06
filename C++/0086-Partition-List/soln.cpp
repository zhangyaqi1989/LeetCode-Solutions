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
    ListNode* partition(ListNode* head, int x) {
        ListNode * left = new ListNode(0);
        ListNode * right = new ListNode(0);
        ListNode * cur_left = left;
        ListNode * cur_right = right;
        while (head != nullptr) {
            if (head->val < x) {
                cur_left->next = head;
                cur_left = cur_left->next;
            } else {
                cur_right->next = head;
                cur_right = cur_right->next;
            }
            head = head->next;
        }
        cur_left->next = right->next;
        cur_right->next = nullptr;
        return left->next;
    }
};
