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
        vector<ListNode*> nodes;
        while (head != nullptr) {
            nodes.push_back(head);
            head = head->next;
        }
        sort(nodes.begin(), nodes.end(), [&](ListNode * a, ListNode * b) {return a->val < b->val;});
        nodes.push_back(nullptr);
        int n = nodes.size();
        for(int i = 0; i < n - 1; ++i) nodes[i]->next = nodes[i + 1];
        return nodes[0];
    }
};
