/*
// Definition for a Node.
class Node {
    public int val;
    public Node next;
    public Node random;

    public Node() {}

    public Node(int _val,Node _next,Node _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
    public Node copyRandomList(Node head) {
        Map<Node, Node> nodes = new HashMap<>();
        Node dummy = new Node(0);
        Node cur = dummy;
        Node head_copy = head;
        while (head != null) {
            Node node = new Node(head.val, null, null);
            nodes.put(head, node);
            cur.next = node;
            cur = cur.next;
            head = head.next;
        }
        head = head_copy;
        while (head != null) {
            if (head.random != null) {
                nodes.get(head).random = nodes.get(head.random);
            }
            head = head.next;
        }
        return dummy.next;
    }
}
