/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public TreeNode sortedListToBST(ListNode head) {
        List<Integer> vals = new ArrayList<>();
        while (head != null) {
            vals.add(head.val);
            head = head.next;
        }
        return arrayToBST(vals, 0, vals.size());
    }
    
    public TreeNode arrayToBST(List<Integer> vals, int lo, int hi) {
        if (hi <= lo) return null;
        int mid = lo + (hi - lo) / 2;
        TreeNode root = new TreeNode(vals.get(mid));
        root.left = arrayToBST(vals, lo, mid);
        root.right = arrayToBST(vals, mid + 1, hi);
        return root;
    }
}
