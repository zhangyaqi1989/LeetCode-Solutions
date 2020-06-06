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
    public boolean leafSimilar(TreeNode root1, TreeNode root2) {
        Stack<TreeNode> s1 = new Stack<>(), s2 = new Stack<>();
        s1.push(root1);
        s2.push(root2);
        while(!s1.isEmpty() && !s2.isEmpty()) {
            int val1 = dfs(s1);
            int val2 = dfs(s2);
            if (val1 != val2) return false;
        }
        return s1.isEmpty() && s2.isEmpty();
        
    }
    
    public int dfs(Stack<TreeNode> s) {
        while(true) {
            TreeNode node = s.pop();
            if (node.right != null) s.push(node.right);
            if (node.left != null) s.push(node.left);
            if (node.left == null && node.right == null) return node.val;
        }
    }
}
