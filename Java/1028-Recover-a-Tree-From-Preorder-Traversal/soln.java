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
    public TreeNode recoverFromPreorder(String S) {
        TreeNode root = null;
        int lo = 0, n = S.length();
        Stack<TreeNode> stack = new Stack<>();
        while (lo < n) {
            int depth = 0;
            while (lo < n && S.charAt(lo) == '-') {
                ++depth;
                ++lo;
            }
            int val = 0;
            while (lo < n && Character.isDigit(S.charAt(lo))) {
                val = val * 10 + S.charAt(lo) - '0';
                ++lo;
            }
            TreeNode node = new TreeNode(val);
            if (root == null) root = node;
            while (stack.size() > depth) {
                stack.pop();
            }
            if (!stack.empty()) {
                 if (stack.peek().left == null) {
                    stack.peek().left = node;
                } else {
                    stack.peek().right = node;
                }               
            }
            stack.push(node);
            
        }
        return root;
    }
}
