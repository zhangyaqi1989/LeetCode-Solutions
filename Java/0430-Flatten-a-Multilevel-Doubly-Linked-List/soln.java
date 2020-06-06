/*
// Definition for a Node.
class Node {
    public int val;
    public Node prev;
    public Node next;
    public Node child;

    public Node() {}

    public Node(int _val,Node _prev,Node _next,Node _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/
class Solution {
    
    private Node suc;
    public Node flatten(Node head) {
        suc = null;
        post(head);
        return head;
    }
    
    private void post(Node node) {
        if (node != null) {
            post(node.next);
            post(node.child);
            node.next = suc;
            node.child = null;
            if (suc != null) suc.prev = node;
            suc = node;
        }
    }
}
