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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        ListNode * cur = root;
        int cnt = 0;
        while (cur != nullptr) {
            ++cnt;
            cur = cur->next;
        }
        vector<ListNode *> ans;
        int q = cnt / k, r = cnt % k;
        cur = root;
        for(int i = 0; i < k; ++i) {
            ans.push_back(cur);
            if (cur == nullptr) continue;
            int nums;
            if (i < r) {
                nums = q + 1;
            } else {
                nums = q;
            }
            for(int j = 0; j < nums - 1; ++j) cur = cur->next;
            ListNode * temp = cur->next;
            cur->next = nullptr;
            cur = temp;
        }
        return ans;
    }
};
