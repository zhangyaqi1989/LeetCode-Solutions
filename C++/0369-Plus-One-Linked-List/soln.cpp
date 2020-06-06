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
    ListNode* plusOne(ListNode* head) {
        ListNode * cur = head;
        ListNode * ptr = NULL;
        
        while (cur != NULL)
        {
            if(cur->val != 9)
                ptr = cur;
            cur = cur->next;
        }
        // cout << ptr << endl;
        if (ptr == NULL)
        {
            ListNode * first = new ListNode(1);
            first->next = head;
            cur = head;
            while(cur != NULL)
            {
                cur->val = 0;
                cur = cur->next;
            }
            return first;
        } else
        {
            ptr->val += 1;
            ptr = ptr->next;
            while (ptr != NULL)
            {
                ptr->val = 0;
                ptr = ptr->next;
            }
            return head;
        }
    }
};