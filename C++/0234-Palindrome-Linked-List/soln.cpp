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
    bool isPalindrome(ListNode* head) {
        ListNode * fast = head;
        ListNode * slow = head;
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode * right = slow; //...
        if (fast != nullptr) { // odd number
            right = right->next;
        }
        ListNode * left = head;
        ListNode * pre = nullptr;
        while (right != nullptr) {
            ListNode * temp = right->next;
            right->next = pre;
            pre = right;
            right = temp;
        }
        right = pre;
        while (right != nullptr) {
            // cout << left->val << " " << right->val << endl;
            if (right->val != left->val) return false;
            right = right->next;
            left = left->next;
        }
        return true;
    }
};
