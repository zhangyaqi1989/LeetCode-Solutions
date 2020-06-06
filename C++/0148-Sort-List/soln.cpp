/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

bool cmp(const ListNode * a, const ListNode * b) {return a->val < b->val;}
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        vector<ListNode*> nodes;
        while (head != nullptr) {
            nodes.push_back(head);
            head = head->next;
        }
        sort(nodes.begin(), nodes.end(), cmp);
        nodes.push_back(nullptr);
        int n = nodes.size();
        for(int i = 0; i < n - 1; ++i) nodes[i]->next = nodes[i + 1];
        return nodes[0];
    }
};
