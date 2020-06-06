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
    public TreeNode increasingBST(TreeNode root) {
        if (root == null) return null;
        TreeNode nxt = null;
        Stack<TreeNode> stk = new Stack<>();
        TreeNode cur = root;
        while (!stk.isEmpty() || cur != null) {
            while (cur != null) {
                stk.push(cur);
                cur = cur.right;
            }
            cur = stk.pop();
            TreeNode temp = cur.left;
            cur.left = null;
            cur.right = nxt;
            nxt = cur;
            // System.out.println(cur.val);
            cur = temp;
        }
        return nxt;
    }
}
