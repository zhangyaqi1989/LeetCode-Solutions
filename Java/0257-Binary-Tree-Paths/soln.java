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
    public List<String> binaryTreePaths(TreeNode root) {
        List<String> ans = new ArrayList<>();
        List<String> path = new ArrayList<>();
        dfs(root, path, ans);
        return ans;
    }
    
    public void dfs(TreeNode node, List<String> path, List<String> ans) {
        if (node != null) {
            if (node.left == null && node.right == null) {
                path.add(Integer.toString(node.val));
                ans.add(pathToString(path));
                path.remove(path.size() - 1);
            } else {
                path.add(Integer.toString(node.val));
                dfs(node.left, path, ans);
                dfs(node.right, path, ans);
                path.remove(path.size() - 1);
            }
        }
    }
    
    public String pathToString(List<String> path) {
        return String.join("->", path);
    }
}
