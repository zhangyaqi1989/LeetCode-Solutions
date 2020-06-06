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
    public List<Integer> getAllElements(TreeNode root1, TreeNode root2) {
        List<Integer> vals1 = new ArrayList<>();
        inorder(root1, vals1);
        List<Integer> vals2 = new ArrayList<>();
        inorder(root2, vals2);
        int n1 = vals1.size(), n2 = vals2.size();
        List<Integer> vals = new ArrayList<>();
        int i = 0, j = 0;
        while (i < n1 && j < n2) {
            if (vals1.get(i) < vals2.get(j)) vals.add(vals1.get(i++));
            else vals.add(vals2.get(j++));
        }
        while(i < n1) {
            vals.add(vals1.get(i++));
        }
        while(j < n2) {
            vals.add(vals2.get(j++));
        }
        return vals;
    }
    
    private void inorder(TreeNode node, List<Integer> vals) {
        if (node != null) {
            inorder(node.left, vals);
            vals.add(node.val);
            inorder(node.right, vals);
        }
    }
}
