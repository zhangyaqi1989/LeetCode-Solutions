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
        Node dummy = Node(0, nullptr, nullptr, nullptr);
        Node * pre = &dummy;
        dfs(head, & pre);
        if (dummy.next != nullptr)
            dummy.next->prev = nullptr;
        return dummy.next;
    }

private:
    void dfs(Node * node, Node ** pre) {
        if (node != nullptr) {
            // cout << node->val << endl;
            (*pre)->next = node;
            node->prev = (*pre);
            Node * child = node->child;
            node->child = nullptr;
            Node * nxt = node->next;
            node->next = nullptr;
            (*pre) = node;
            dfs(child, pre);
            dfs(nxt, pre);
        }
    }
};
