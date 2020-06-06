/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public boolean isPalindrome(ListNode head) {
        ListNode fast = head, slow = head;
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        ListNode right = slow;
        if (fast != null) right = right.next;
        ListNode pre = null;
        while (right != null) {
            ListNode temp = right.next;
            right.next = pre;
            pre = right;
            right = temp;
        }
        right = pre;
        ListNode left = head;
        while (right != null) {
           if (right.val != left.val) return false;
            left = left.next;
            right = right.next;
        }
        return true;
    }
}
