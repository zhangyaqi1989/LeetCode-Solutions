/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode rotateRight(ListNode head, int k) {
        if(k == 0 || head == null) return head;
        int cnt = 0;
        ListNode cur = head;
        while(cur != null) {
            ++cnt;
            cur = cur.next;
        }
        k = k % cnt;
        if(k == 0) return head;
        ListNode fast = head;
        ListNode slow = head;
        for(int i = 0; i < k; ++i) fast = fast.next;
        while(fast.next != null) {
            fast = fast.next;
            slow = slow.next;
        }
        ListNode new_head = slow.next;
        slow.next = null;
        fast.next = head;
        return new_head;
        
    }
}
