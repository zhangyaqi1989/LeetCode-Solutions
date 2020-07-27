/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public int cnt;
    public int countPairs(TreeNode root, int distance) {
        cnt = 0;
        postprocess(root, distance);
        return cnt;
    }
    
    private int [] postprocess(TreeNode node, int distance) {
        int [] counter = new int [11];
        if(node == null) {
            return counter;
        }
        int [] left = postprocess(node.left, distance);
        int [] right = postprocess(node.right, distance);
        if(node.left == null && node.right == null) {
            counter[0] = 1;
            return counter;
        }
        for(int i = 1; i < distance; ++i) {
            for(int j = 1; j + i <= distance; ++j) {
                cnt += left[i - 1] * right[j - 1];
            }
        }
        for(int i = 0; i < distance; ++i) {
            counter[i + 1] += left[i] + right[i];
        }
        return counter;
    }
}
