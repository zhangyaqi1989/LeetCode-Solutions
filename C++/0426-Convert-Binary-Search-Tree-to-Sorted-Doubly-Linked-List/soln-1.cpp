/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        // inorder traverse
        if (root == nullptr) return root;
        Node * head = nullptr;
        Node * pre = nullptr;
        Node * temp;
        Node * cur = root;
        stack<Node *> s;
        while (cur != nullptr || !s.empty()) {
            while (cur != nullptr) {
                s.push(cur);
                cur = cur->left;
            }
            cur = s.top();
            s.pop();
            if (pre == nullptr) {
                head = cur; 
            } else {
                pre->right = cur;
                cur->left = pre;
            }
            pre = cur;
            cur = cur->right;
        }
        head->left = pre;
        pre->right = head;
        return head;
    }
};
