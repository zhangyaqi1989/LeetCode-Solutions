/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/
class Solution {
public:
    Node* inorderSuccessor(Node* node) {
        if (node == nullptr) return nullptr;
        if (node->right == nullptr) {
            Node * cur = node;
            while (cur->parent != nullptr && cur->parent->val < node->val) {
                cur = cur->parent;
            }
            return cur->parent;
        }
        else {
            Node * cur = node->right;
            while(cur->left) {
                cur = cur->left;
            }
            return cur;
        }
    }
};
