/*
// Definition for a Node.
class Node {
    public int val;
    public Node left;
    public Node right;
    public Node parent;
};
*/
class Solution {
    public Node inorderSuccessor(Node x) {
        if (x == null) return null;
        if (x.right != null) {
            Node cur = x.right;
            while (cur.left != null) {
                cur = cur.left;
            }
            return cur;
        } else {
            Node cur = x.parent;
            while (cur != null && cur.val < x.val) cur = cur.parent;
            return cur;
        }
    }
}
