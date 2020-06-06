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
    bool hasCycle(ListNode *head) {
        if(head == nullptr) return false;
        ListNode * fast = head->next;
        ListNode * slow = head;
        while(fast != nullptr && fast->next != nullptr) {
            if(fast == slow) return true;
            slow = slow->next;
            fast = fast->next->next;
        }
        return false;
    }
};
