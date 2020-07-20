/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteNodes(ListNode* head, int m, int n) {
        ListNode * cur = head;
        while(cur != nullptr) {
            for(int i = 0; i < m - 1; ++i) {
                if (cur != nullptr) {
                    cur = cur->next;
                }
            }
            ListNode * temp = cur;
            for(int i = 0; i < n + 1; ++i) {
                if(temp != nullptr) {
                    temp = temp->next;
                }
            }
            if(cur != nullptr) {
                cur->next = temp;
                cur = temp;
            }
        }
        return head;
    }
};
