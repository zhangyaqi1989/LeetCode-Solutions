/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Codec {

    private void preorder(TreeNode node, List<String> vals) {
        if (node == null) {
            vals.add("#");
        } else {
            vals.add(Integer.toString(node.val));
            preorder(node.left, vals);
            preorder(node.right, vals);
        }
    }
    
    public TreeNode build(String[] tokens, int [] idx) {
        String token = tokens[idx[0]++];
        if (token.equals("#")) return null;
        else {
            TreeNode root = new TreeNode(Integer.parseInt(token));
            root.left = build(tokens, idx);
            root.right = build(tokens, idx);
            return root;
        }
    }
    
    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        List<String> vals = new ArrayList<>();
        preorder(root, vals);
        return String.join(" ", vals);
    }
    

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        String[] tokens = data.split(" ");
        int [] idx  = {0};
        return build(tokens, idx);
    }
    
    
}

// Your Codec object will be instantiated and called as such:
// Codec codec = new Codec();
// codec.deserialize(codec.serialize(root));
