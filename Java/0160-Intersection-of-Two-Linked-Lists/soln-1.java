/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        Set<ListNode> seen = new HashSet<>();
        ListNode curA = headA, curB = headB;
        while (curA != null || curB != null) {
            if (curA != null && seen.contains(curA)) return curA;
            if (curA != null) {
                seen.add(curA);
                curA = curA.next;
            }
            if (curB != null && seen.contains(curB)) return curB;
            if (curB != null) {
                seen.add(curB);
                curB = curB.next;
            }
        }
        return null;
    }
}
