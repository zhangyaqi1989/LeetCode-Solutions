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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode *> seen;
        while (headA || headB) {
            if (headA != nullptr) {
                if (seen.count(headA)) return headA;
                seen.insert(headA);
                headA = headA->next;
            }
            if (headB != nullptr) {
                if (seen.count(headB)) return headB;
                seen.insert(headB);
                headB = headB->next;
            }
        }
        return nullptr;
    }
};
