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

// ALG: recursion

auto desyncio = []()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();


class Solution {
public:
    Node* flatten(Node* head) {
        Node* cur = head;
        while(cur) {
            if (cur->child) {
                Node* child = flatten(cur->child);
                cur->child = nullptr;
                Node* nxt = cur->next;
                child->prev = cur;
                cur->next = child;
                while(child->next) child = child->next;
                child->next = nxt;
                if (nxt) nxt->prev = child;
                cur = nxt;
            } else cur = cur->next;
        }
        return head;
    }
};
