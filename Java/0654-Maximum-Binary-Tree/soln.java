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
    public TreeNode constructMaximumBinaryTree(int[] nums) {
        return buildTree(0, nums.length, nums);
    }

    private TreeNode buildTree(int lo, int hi, int [] nums) {
        if (lo + 1 > hi) return null;
        int mx = nums[lo], mx_idx = lo;
        for(int i = lo; i < hi; ++i) {
            if(nums[i] > mx) {
                mx = nums[i];
                mx_idx = i;
            }
        }
        TreeNode root = new TreeNode(mx);
        root.left = buildTree(lo, mx_idx, nums);
        root.right = buildTree(mx_idx + 1, hi, nums);
        return root;
    }
}
