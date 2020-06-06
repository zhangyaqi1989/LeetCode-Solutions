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
        Node * tail = root;
        while (tail != nullptr) {
            Node * pre = nullptr;
            Node * nxt_level = tail->left;
            while (tail != nullptr) {
                if (tail->left != nullptr) {
                    tail->left->next = tail->right;
                    if (pre != nullptr) pre->right->next = tail->left;
                }
                pre = tail;
                tail = tail->next;
            }
            tail = nxt_level;
        }
        return root;
    }
};
