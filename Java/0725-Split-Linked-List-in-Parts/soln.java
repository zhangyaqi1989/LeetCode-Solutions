/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode[] splitListToParts(ListNode root, int k) {
        ListNode cur = root;
        int cnt = 0;
        while (cur != null) {
            ++cnt;
            cur = cur.next;
        }
        int q = cnt / k, r = cnt % k;
        ListNode [] ans = new ListNode[k];
        cur = root;
        for(int i = 0; i < k; ++i) {
            ans[i] = cur;
            if (cur == null) continue;
            int num;
            if (i < r) num = q + 1;
            else num = q;
            for(int j = 0; j < num - 1; ++j) cur = cur.next;
            ListNode temp = cur.next;
            cur.next = null;
            cur = temp;
        }
        return ans;
    }
}
