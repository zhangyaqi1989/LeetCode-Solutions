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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode dummy = ListNode(-1);
        dummy.next = head;
        int acc = 0;
        unordered_map<int, ListNode *> seen;
        seen.insert({acc, &dummy});
        while (head != nullptr) {
            acc += head->val;
            auto it = seen.find(acc);
            if (it != seen.end()) {
                int temp = acc;
                ListNode * cur = it->second->next;
                while(true) {
                    temp += cur->val;
                    if (temp != acc) seen.erase(temp);
                    else break;
                    cur = cur->next;
                }
                it->second->next = head->next;
            } else {
                seen.insert({acc, head});
            }
            head = head->next;
        }
        return dummy.next;
    }
};
