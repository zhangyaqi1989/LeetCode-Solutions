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
    public int greater;
    public TreeNode convertBST(TreeNode root) {
        greater = 0;
        postorder(root);
        return root;
    }
    
    public void postorder(TreeNode node) {
        if (node != null) {
            postorder(node.right);
            int temp = node.val;
            node.val += greater;
            greater += temp;
            postorder(node.left);
        }
    }
}
