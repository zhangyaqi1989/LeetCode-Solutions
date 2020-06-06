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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL || k == 1) return head;
        int cnt = 0;
        ListNode * dummy = new ListNode(-1);
        dummy->next = head;
        ListNode * cur = dummy;
        ListNode * nxt, *pre = dummy;
        while (cur = cur->next) ++cnt; // number of nodes
        while(cnt >= k) {
            cur = pre->next;
            nxt = cur->next;
            for(int i = 1; i < k; ++i) {
                cur->next = nxt->next;
                nxt->next = pre->next;
                pre->next = nxt;
                nxt = cur->next;
            }
            pre = cur;
            cnt -= k;
        }
        return dummy->next;  
    }
};