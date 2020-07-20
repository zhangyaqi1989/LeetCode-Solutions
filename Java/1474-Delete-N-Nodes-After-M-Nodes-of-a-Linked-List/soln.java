/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode deleteNodes(ListNode head, int m, int n) {
        ListNode cur = head;
        while(cur != null) {
            for(int i = 0; i < m - 1; ++i) {
                if(cur != null) cur = cur.next;
            }
            ListNode temp = cur;
            for(int i = 0; i < n + 1; ++i) {
                if(temp != null) temp = temp.next;
            }
            if(cur != null) {
                cur.next = temp;
                cur = temp;
            }
        }
        return head;
    }
}
