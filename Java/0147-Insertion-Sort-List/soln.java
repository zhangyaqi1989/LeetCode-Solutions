/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode insertionSortList(ListNode head) {
        ListNode dummy = new ListNode(Integer.MIN_VALUE);
        while (head != null) {
            ListNode cur = dummy;
            while (cur.next != null && cur.next.val < head.val) {
                cur = cur.next;
            }
            ListNode nxt = head.next;
            head.next = cur.next;
            cur.next = head;
            head = nxt;
        }
        return dummy.next;
    }
}
