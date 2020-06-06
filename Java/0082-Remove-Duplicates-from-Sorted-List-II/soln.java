/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode pre = dummy, cur = head, node = head;
        int cnt = 0;
        while (cur != null) {
            if (cur.val == node.val) {
                ++cnt;
            } else {
                if (cnt == 1) {
                    pre.next = node;
                    pre = pre.next;
                }
                cnt = 1;
                node = cur;
            }
            cur = cur.next;
        }
        if (cnt == 1) {
            pre.next = node;
            node.next = null;
        } else {
            pre.next = null;
        }
        return dummy.next;
    }
}
