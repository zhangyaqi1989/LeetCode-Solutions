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
    public List<Integer> postorderTraversal(TreeNode root) {
        List<Integer> vals = new ArrayList<Integer>();
        Stack<TreeNode> stk = new Stack<>();
        TreeNode cur = root;
        while (cur != null || !stk.isEmpty()) {
            while (cur != null) {
                vals.add(cur.val);
                stk.push(cur);
                cur = cur.right;
            }
            cur = stk.pop();
            cur = cur.left;
        }
        Collections.reverse(vals);
        return vals;
    }
}
