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
    public int cameras;
    public int minCameraCover(TreeNode root) {
        // 0: not covered;
        // 1: covered, without camera on it
        // 2: covered, with camera on it
        cameras = 0;
        if (postorder(root) == 0) ++cameras;
        return cameras;
    }
    
    public int postorder(TreeNode node) {
        if (node != null) {
            int l = postorder(node.left);
            int r = postorder(node.right);
            if (l == 0 || r == 0) {
                ++cameras;
                return 2;
            } else if (l == 2 || r == 2) {
                return 1;
            } else {
                return 0;
            }
        } else {
            return 1;
        }
    }
    
    
}
