/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/
class Solution {
public:
    Node* flatten(Node* head) {
        Node * suc = nullptr;
        postorder(head, &suc);
        return head;
    }
    
private:
    void postorder(Node * node, Node ** suc) {
        if (node != nullptr) {
            postorder(node->next, suc);
            postorder(node->child, suc);
            node->child = nullptr;
            node->next = *suc;
            if (*suc != nullptr) (*suc)->prev = node;
            *suc = node;
        }
    }
};
