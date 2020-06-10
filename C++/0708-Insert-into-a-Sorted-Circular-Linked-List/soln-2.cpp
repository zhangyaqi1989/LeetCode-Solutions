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
        Node * node = new Node(insertVal, nullptr);
        if (head == nullptr) {
            node->next = node;
            return node;
        }
        Node * cur = head;
        while(cur->next != head) {
            if (insertVal >= cur->val && insertVal <= cur->next->val) {
                break;
            }
            if (cur->next->val < cur->val) {
                if (insertVal >= cur->val || insertVal <= cur->next->val) {
                    break;
                }
            }
            cur = cur->next;
        }
        node->next = cur->next;
        cur->next = node;
        return head;
    }
};
