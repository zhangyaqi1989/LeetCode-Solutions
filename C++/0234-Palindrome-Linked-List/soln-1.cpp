/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> vals;
        while(head != nullptr) {
            vals.push_back(head->val);
            head = head->next;
        }
        int n = vals.size();
        int lo = 0, hi = n - 1;
        while(lo < hi) {
            if(vals[lo++] != vals[hi--]) return false;
        }
        return true;
    }
};
