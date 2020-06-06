/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // first traverse the list and create copy of every nod
        map<Node *, Node *> nodes;
        Node * cur = head;
        while(cur != nullptr) {
            nodes.insert({cur, new Node(cur->val)});
            cur = cur->next;
        }
        // traverse it again and populate next and random fields
        cur = head;
        while(cur != nullptr) {
            if(cur->next != nullptr) nodes[cur]->next = nodes[cur->next];
            if(cur->random != nullptr) nodes[cur]->random = nodes[cur->random];
            cur = cur->next;
        }
        return nodes[head];
    }
};
