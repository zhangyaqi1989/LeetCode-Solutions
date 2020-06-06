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
        ListNode * even_head = new ListNode(0);
        ListNode * odd_head = new ListNode(1);
        ListNode * even = even_head;
        ListNode * odd = odd_head;
        int cur = 1;
        while (head != nullptr) {
            if (cur & 1 == 1) {
                odd->next = head;
                odd = odd->next;
            } else {
                even->next = head;
                even = even->next;
            }
            cur ^= 1;
            head = head->next;
        }
        // odd->next = nullptr;
        even->next = nullptr;
        odd->next = even_head->next;
        ListNode * ans = odd_head->next;
        delete even_head;
        delete odd_head;
        return ans;
    }
};
