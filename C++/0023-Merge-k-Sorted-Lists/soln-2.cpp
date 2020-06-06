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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode dummy = ListNode(0);
        ListNode * cur = & dummy;
        auto comp = [] (ListNode * a, ListNode * b) {return a->val > b->val;};
        priority_queue<ListNode*, vector<ListNode *>, decltype(comp)> pq(comp);
        for(auto head : lists) {
            if (head != nullptr) {
                pq.push(head);
            }
        }
        while (!pq.empty()) {
            ListNode * node = pq.top();
            pq.pop();
            cur->next = node;
            cur = cur->next;
            if (cur->next != nullptr) {
                pq.push(cur->next);
            }
        }
        cur->next = nullptr;
        return dummy.next;
    }
};
