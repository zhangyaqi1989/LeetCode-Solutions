/*
// Definition for a Node.
class Node {
    public int val;
    public Node next;

    public Node() {}

    public Node(int _val,Node _next) {
        val = _val;
        next = _next;
    }
};
*/
class Solution {
    public Node insert(Node head, int insertVal) {
        if (head == null) return new Node(insertVal, null);
        Node pre = head;
        Node cur = head.next;
        while (cur != head) {
            if (pre.val <= insertVal && insertVal <= cur.val) break;
            else if (pre.val > cur.val && (insertVal > pre.val || insertVal < cur.val)) break;
            pre = pre.next;
            cur = cur.next;
        }
        Node node = new Node(insertVal, cur);
        pre.next = node;
        return head;
    }
}
