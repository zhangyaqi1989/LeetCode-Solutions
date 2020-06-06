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
    public int ans;
    public int pseudoPalindromicPaths (TreeNode root) {
        int [] counter = new int [10];
        Arrays.fill(counter, 0);
        ans = 0;
        dfs(root, counter);
        return ans;
    }
    
    private void dfs(TreeNode node, int [] counter) {
        if(node != null) {
            ++counter[node.val];
            if(node.left == null && node.right == null) {
                int cnt = 0;
                for(int i = 1; i <= 9; ++i) cnt += counter[i] % 2;
                if(cnt <= 1) ++ans;
            }
            dfs(node.left, counter);
            dfs(node.right, counter);
            --counter[node.val];
        }
    }
}
