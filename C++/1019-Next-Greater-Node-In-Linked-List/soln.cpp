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
    vector<int> nextLargerNodes(ListNode* head) {
        ListNode * cur = head;
        vector<int> nums;
        int cnt = 0;
        while (cur != nullptr) {
            nums.push_back(cur->val);
            ++cnt;
            cur = cur->next;
        }
        stack<int> stk;
        vector<int> ans(cnt, 0);
        for(int i = 0; i < cnt; ++i) {
            while (!stk.empty() && nums[i] > nums[stk.top()]) {
                ans[stk.top()] = nums[i];
                stk.pop();
            }
            stk.push(i);
        }
        return ans;
    }
};
