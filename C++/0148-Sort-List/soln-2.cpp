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
        ListNode * fast = head;
        ListNode * slow = head;
        ListNode * pre = head;
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            pre = slow;
            slow = slow->next;
        }
        if (fast == slow) return head;
        ListNode * l2 = pre->next;
        pre->next = nullptr;
        l2 = sortList(l2);
        ListNode * l1 = sortList(head);
        return MergeList(l1, l2);
    }
    
private:
    ListNode * MergeList(ListNode * l1, ListNode * l2) {
        ListNode dummy = ListNode(0);
        ListNode * cur = & dummy;
        while (l1 != nullptr && l2 != nullptr) {
            if(l2->val < l1->val) swap(l1, l2);
            cur->next = l1;
            cur = cur->next;
            l1 = l1->next;
        }
        if (l1!= nullptr) cur->next = l1;
        else cur->next = l2;
        return dummy.next;
    }
};
