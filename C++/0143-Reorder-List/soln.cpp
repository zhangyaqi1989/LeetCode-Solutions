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
    void reorderList(ListNode* head) {
        ListNode * fast = head;
        ListNode * slow = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode * pre = nullptr;
        ListNode * cur = slow;
        while(cur != nullptr) {
            ListNode * temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        ListNode * first = head;
        ListNode * second = pre;
        int cnt = 0;
        ListNode * dummy = new ListNode(0);
        cur = dummy;
        while (first != nullptr && second != nullptr) {
            // cout << first->val << endl;
            // cout << second->val << endl;
            if (cnt % 2 == 0) {
                cur->next = first;
                first = first->next;
            } else {
                cur->next = second;
                second = second->next;
            }
            cur = cur->next;
            ++cnt;
        }
    }
};
