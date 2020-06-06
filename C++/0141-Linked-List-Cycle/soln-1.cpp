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
        unordered_set<ListNode *> nodes;
        ListNode * cur = head;
        while (cur != nullptr) {
            if (nodes.find(cur) != nodes.end()) return true;
            nodes.insert(cur);
            cur = cur->next;
        }
        return false;
    }
};
