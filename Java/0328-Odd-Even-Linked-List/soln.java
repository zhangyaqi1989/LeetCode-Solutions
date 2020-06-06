/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode oddEvenList(ListNode head) {
        ListNode odd_head = new ListNode(1);
        ListNode even_head = new ListNode(1);
        ListNode odd = odd_head, even = even_head;
        int cnt = 1;
        while (head != null) {
            if (cnt % 2 == 0) {
                even.next = head;
                even = even.next;
            } else {
                odd.next = head;
                odd = odd.next;
            }
            cnt = 1 - cnt;
            head = head.next;
        }
        odd.next = even_head.next;
        even.next = null;
        return odd_head.next;
    }
}
