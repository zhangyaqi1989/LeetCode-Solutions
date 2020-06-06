/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */

class Record {
    public boolean is_bst;
    public int mn;
    public int mx;
    public int sum;
    
    public Record(boolean is_bst, int mn, int mx, int sum) {
        this.is_bst = is_bst;
        this.mn = mn;
        this.mx = mx;
        this.sum = sum;
    }
}

class Solution {
    private int ans;
    public int maxSumBST(TreeNode root) {
        ans = 0;
        Postorder(root);
        return ans;
    }
    
    private Record Postorder(TreeNode root) {
        if (root == null) return new Record(true, Integer.MAX_VALUE, Integer.MIN_VALUE, 0);
        Record left = Postorder(root.left);
        Record right = Postorder(root.right);
        int mn = Math.min(root.val, Math.min(left.mn, right.mn));
        int mx = Math.max(root.val, Math.max(left.mx, right.mx));
        boolean is_bst = false;
        int sum = root.val + left.sum + right.sum;
        if(left.is_bst && right.is_bst && left.mx < root.val && root.val < right.mn) {
            ans = Math.max(ans, sum);
            is_bst = true;
        }
        return new Record(is_bst, mn, mx, sum);
    }
}
