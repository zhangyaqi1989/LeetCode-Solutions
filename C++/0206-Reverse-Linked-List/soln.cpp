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
        ListNode * pre = NULL;
        ListNode * cur = head;
        while (cur != NULL) {
            ListNode * pre_temp = pre;
            pre = cur;
            ListNode * next_temp = cur->next;
            cur->next = pre_temp;
            cur = next_temp;
        }
        return pre;
    }
};