/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val,List<Node> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
    public List<Integer> preorder(Node root) {
        List<Integer> vals = new ArrayList<>();
        helper(root, vals);
        return vals;
    }
    
    public void helper(Node node, List<Integer> vals) {
        if (node != null) {
            vals.add(node.val);
            for(Node child : node.children) {
                helper(child, vals);
            }
        }
    }
}
