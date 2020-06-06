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
    int numComponents(ListNode* head, vector<int>& G) {
        int cnt = 0;
        ListNode * last = nullptr;
        unordered_set<int> s(G.begin(), G.end());
        while (head != nullptr) {
            int val = head->val;
            if (s.count(val)) {
                if (last == nullptr || last->next->val != val) {
                    ++cnt;
                }
                last = head;
            }
            head = head->next;
        }
        return cnt;
    }
};
