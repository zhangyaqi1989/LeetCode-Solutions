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
    public TreeNode constructFromPrePost(int[] pre, int[] post) {
        return build(pre, post, 0, pre.length, 0, post.length);
    }
    
    public TreeNode build(int[] pre, int[] post, int pre_lo, int pre_hi, int post_lo, int post_hi) {
        if (pre_lo >= pre_hi) return null;
        TreeNode root = new TreeNode(pre[pre_lo]);
        Set<Integer> seen = new HashSet<>();
        for(int idx = pre_lo + 1; idx < pre_hi; ++idx) {
            for(int val : new int[] {pre[idx], post[post_lo + idx - pre_lo - 1]}) {
                if (seen.contains(val)) {
                    seen.remove(val);
                } else {
                    seen.add(val);
                }
            }
            if (seen.size() == 0) {
                root.left = build(pre, post, pre_lo + 1, idx + 1, post_lo, post_lo + idx - pre_lo);
                root.right = build(pre, post, idx + 1, pre_hi, post_lo + idx - pre_lo, post_hi - 1);
                break;
            }
        }
        return root;
    }
}
