/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public int[] nextLargerNodes(ListNode head) {
        List<Integer> nums = new ArrayList<>();
        ListNode cur = head;
        int cnt = 0;
        while (cur != null) {
            ++cnt;
            nums.add(cur.val);
            cur = cur.next;
        }
        int[] ans = new int[cnt];
        Stack<Integer> stk = new Stack<>();
        for(int i = 0; i < cnt; ++i) {
            while (!stk.isEmpty() && nums.get(i) > nums.get(stk.peek())) {
                ans[stk.pop()] = nums.get(i);
            }
            stk.push(i);
        }
        return ans;
    }
}
