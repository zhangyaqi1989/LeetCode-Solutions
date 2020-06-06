/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/
class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        // any single node in the list
        if (head == nullptr) {
            Node * node = new Node(insertVal);
            node->next = node;
            return node;
        }
        Node * cur = head;
        do {
            if (cur->next->val >= cur->val) {
                if (cur->val <= insertVal && insertVal <= cur->next->val) {
                    break;
                }
            } else {
                if (insertVal > cur->val || insertVal < cur->next->val) {
                    break;
                }
            }
            cur = cur->next;
        } while (cur != head);
        Node * node = new Node(insertVal);
        node->next = cur->next;
        cur->next = node;
        return head;
    }
};
