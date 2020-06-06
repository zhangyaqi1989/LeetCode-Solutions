/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        Node * level = root;
        while (level != nullptr) {
            Node dummy = Node(0, nullptr, nullptr, nullptr);
            Node * cur = & dummy;
            while(level != nullptr) {
                if (level->left != nullptr) {
                    cur->next = level->left;
                    cur = cur->next;
                }
                if (level->right != nullptr) {
                    cur->next = level->right;
                    cur = cur->next;
                }
                level = level->next;
            }
            level = dummy.next;
        }
        return root;
    }
};
