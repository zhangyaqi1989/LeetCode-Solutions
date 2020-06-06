/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class CBTInserter {
    
    private List<TreeNode> tree;
    private int nxt;

    public CBTInserter(TreeNode root) {
        tree = new ArrayList<>();
        tree.add(null);
        Queue<TreeNode> frontier = new LinkedList<>();
        frontier.offer(root);
        while (!frontier.isEmpty()) {
            TreeNode node = frontier.poll();
            tree.add(node);
            if (node.left != null) {
                frontier.offer(node.left);
            }
            if (node.right != null) {
                frontier.offer(node.right);
            }
        }
        nxt = tree.size();
    }
    
    public int insert(int v) {
        TreeNode node = new TreeNode(v);
        TreeNode parent = tree.get(nxt / 2);
        if (nxt % 2 == 1) {
            parent.right = node;
        } else {
            parent.left = node;
        }
        tree.add(node);
        ++nxt;
        return parent.val;
    }
    
    public TreeNode get_root() {
        return tree.get(1);
    }
}

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter obj = new CBTInserter(root);
 * int param_1 = obj.insert(v);
 * TreeNode param_2 = obj.get_root();
 */
