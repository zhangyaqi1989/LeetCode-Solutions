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
        priority_queue<pair<int, ListNode*>> q;
        for (auto lst : lists)
        {
            if (lst != nullptr) q.push(make_pair(-lst->val, lst));
        }
        ListNode * head = new ListNode(0);
        ListNode * cur = head;
        while (!q.empty())
        {
            pair<int, ListNode*> p = q.top();
            ListNode * node = p.second;
            q.pop();
            cur->next = node;
            cur = cur->next;
            if (node->next != nullptr) q.push(make_pair(-node->next->val, node->next));
        }
        return head->next;
    }
};