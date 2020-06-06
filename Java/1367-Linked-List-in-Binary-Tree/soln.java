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
    public boolean isSubPath(ListNode head, TreeNode root) {
        if (root == null) return head == null;
        return helper(head, root) || isSubPath(head, root.left) || isSubPath(head, root.right);
    }
    
    public boolean helper(ListNode cur, TreeNode node) {
        if (cur == null) return true;
        if (node == null) return false;
        return cur.val == node.val && (helper(cur.next, node.left) || helper(cur.next, node.right));
    }
}
