/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode dummy = new ListNode(-1);
        ListNode cur = dummy;
        int carry = 0;
        while(l1 != null || l2 != null) {
            int v1 = (l1 == null ? 0 : l1.val);
            int v2 = (l2 == null ? 0 : l2.val);
            int v = v1 + v2 + carry;
            carry = v / 10;
            if (l1 != null) l1 = l1.next;
            if (l2 != null) l2 = l2.next;
            cur.next = new ListNode(v % 10);
            cur = cur.next;
        }
        if (carry != 0) {
            cur.next = new ListNode(carry);
            cur = cur.next;
        }
        cur.next = null;
        return dummy.next;
    }
}
