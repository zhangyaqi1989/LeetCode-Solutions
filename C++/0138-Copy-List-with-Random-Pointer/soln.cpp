/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node * dummy = new Node(0, nullptr, nullptr);
        Node * cur = dummy;
        Node * wcur = head;
        map<Node *, Node *> nodes;
        while (wcur != nullptr) {
            Node * node = new Node(wcur->val,nullptr, nullptr);
            nodes[wcur] = node;
            cur->next = node;
            cur = cur->next;
            wcur = wcur->next;
        }
        wcur = head;
        while (wcur != nullptr) {
            if (wcur->random != nullptr) {
                nodes[wcur]->random = nodes[wcur->random];
            }
            wcur = wcur->next;
        }
        return dummy->next;
    }
};
