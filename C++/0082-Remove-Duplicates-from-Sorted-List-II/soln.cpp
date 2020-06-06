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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode * dummy = new ListNode(0);
        dummy->next = head;
        ListNode * cur = head;
        ListNode * pre = dummy;
        int cnt = 0;
        ListNode * node = head;
        while (cur != nullptr) {
            if (cur->val == node->val) {
                ++cnt;
            } else {
                if (cnt == 1) {
                    pre->next = node;
                    pre = pre->next;
                }
                cnt = 1;
                node = cur;
            }
            cur = cur->next;
        }
        if (cnt == 1) {
            pre->next = node;
            node->next = nullptr;
        } else {
            pre->next = nullptr;
        }
        ListNode * ans = dummy->next;
        delete dummy;
        return ans;
    }
};
