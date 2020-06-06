/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode reverseBetween(ListNode head, int m, int n) {
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode left = dummy;
        for(int i = 0; i < m - 1; ++i) left = left.next;
        ListNode pre = null;
        ListNode cur = left.next;
        ListNode nxt = null;
        for(int i = 0; i < n - m + 1; ++i) {
            nxt = cur.next;
            cur.next = pre;
            pre = cur;
            cur = nxt;
        }
        left.next.next = nxt;
        left.next = pre;
        return dummy.next;
    }
}
