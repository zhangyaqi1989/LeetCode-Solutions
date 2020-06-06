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
    ListNode* oddEvenList(ListNode* head) {
        ListNode odd_head = ListNode(0), even_head = ListNode(0);
        ListNode * odd_cur = & odd_head;
        ListNode * even_cur = & even_head;
        bool is_odd = true;
        while (head != nullptr) {
            if (is_odd) {
                odd_cur->next = head;
                odd_cur = odd_cur->next;
            } else {
                even_cur->next = head;
                even_cur = even_cur->next;
            }
            head = head->next;
            is_odd = !is_odd;
        }
        even_cur->next = nullptr;
        odd_cur->next = even_head.next;
        return odd_head.next;
    }
};
