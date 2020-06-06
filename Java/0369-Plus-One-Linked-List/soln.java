/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode plusOne(ListNode head) {
        ListNode dummy = new ListNode(1);
        dummy.next = head;
        ListNode not_nine = dummy;
        while (head != null) {
            if (head.val != 9) not_nine = head;
            head = head.next;
        }
        ListNode cur = not_nine.next;
        while (cur != null) {
            cur.val = 0;
            cur = cur.next;
        }
        if (not_nine == dummy) {
            return dummy;
        } else {
            not_nine.val += 1;
            return dummy.next;
        }
    }
}
