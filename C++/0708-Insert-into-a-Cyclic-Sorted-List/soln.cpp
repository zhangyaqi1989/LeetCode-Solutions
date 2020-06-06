/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/
class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        if (head == nullptr) return new Node(insertVal, nullptr);
        Node * pre = head;
        Node * cur = head->next;
        while (cur != head) {
            if (pre->val <= insertVal && insertVal <= cur->val) break;
            if (pre->val > cur->val && (insertVal > pre->val || insertVal < cur->val))
                break;
            pre = pre->next;
            cur = cur->next;
        }
        Node * node = new Node(insertVal, cur);
        pre->next = node;
        return head;
    }
};
