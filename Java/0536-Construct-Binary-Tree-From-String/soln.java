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
    public TreeNode str2tree(String s) {
        int[] i = new int[1];
        return s.length() == 0 ? null : build(s, i);
    }
    
    public TreeNode build(String s, int[] i) {
        int start = i[0];
        while (i[0] < s.length() && s.charAt(i[0]) != '(' && s.charAt(i[0]) != ')')
            ++i[0];
        int val = Integer.parseInt(s.substring(start, i[0]));
        TreeNode root = new TreeNode(val);
        if (i[0] < s.length() && s.charAt(i[0]) == '(') {
            ++i[0];
            root.left = build(s, i);
            ++i[0];
        }
        if (i[0] < s.length() && s.charAt(i[0]) == '(') {
            ++i[0];
            root.right = build(s, i);
            ++i[0];
        }
        return root;
    }
}
