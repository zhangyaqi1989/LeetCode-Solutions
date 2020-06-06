/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public int numComponents(ListNode head, int[] G) {
        Set<Integer> pool = new HashSet<>();
        for(int num : G) pool.add(num);
        int ans = 0;
        int pre = -1;
        while(head != null) {
            if(pool.contains(head.val)) {
               if (pre == -1 || !pool.contains(pre)) ++ans; 
            }
            pre = head.val;
            head = head.next;
        }
        return ans;
    }
}
