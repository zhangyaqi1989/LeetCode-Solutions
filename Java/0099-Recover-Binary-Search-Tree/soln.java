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
    public void recoverTree(TreeNode root) {
        Stack<TreeNode> stk = new Stack<>();
        TreeNode x = null, y = null, pred = null, cur = root;
        while (!stk.isEmpty() || cur != null) {
            while (cur != null) {
                stk.push(cur);
                cur = cur.left;
            }
            cur = stk.pop();
            if (pred != null && cur.val < pred.val) {
                y = cur;
                if (x == null) {
                    x = pred;
                } else {
                    break;
                }
            }
            pred = cur;
            cur = cur.right;
        }
        int temp = x.val;
        x.val = y.val;
        y.val = temp;
    }
}
