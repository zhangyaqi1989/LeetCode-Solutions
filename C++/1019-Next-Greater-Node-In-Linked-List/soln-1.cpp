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
        stack<int> stk;
        vector<int> ans, nums;
        int i = 0;
        while (head != nullptr) {
            int num = head->val;
            nums.push_back(num);
            while(!stk.empty() && num > nums[stk.top()]) {
                ans[stk.top()] = num;
                stk.pop();
            }
            stk.push(i++);
            ans.push_back(0);
            head = head->next;
        } 
        return ans;
    }
};
