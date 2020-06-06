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
    ListNode* rotateRight(ListNode* head, int k) {
        if (k == 0) return head;
        int cnt = 0;
        ListNode* cur = head;
        ListNode* pre = nullptr;
        while(cur) {
            pre = cur;
            cur = cur->next;
            ++cnt;
        }
        if (cnt == 0) return head;
        k %= cnt;
        if(k == 0) return head;
        int m = cnt - k - 1;
        cur = head;
        while(m-- > 0) cur = cur->next;
        ListNode* newHead = cur->next;
        cur->next = nullptr;
        pre->next = head;
        return newHead;
    }
};
