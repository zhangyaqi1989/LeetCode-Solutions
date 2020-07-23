/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     Node *left;
 *     Node *right;
 *     Node *random;
 *     Node() : val(0), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x) : val(x), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x, Node *left, Node *right, Node *random) : val(x), left(left), right(right), random(random) {}
 * };
 */

class Solution {
public:
    NodeCopy * copyRandomBinaryTree(Node* root) {
        // How to traverse the tree
        if(root == nullptr) return nullptr;
        map<Node *, NodeCopy *> nodes;
        stack<Node *> stk;
        stk.push(root);
        while(!stk.empty()) {
            Node * node = stk.top();
            NodeCopy * node_copy = new NodeCopy(node->val);
            nodes[node] = node_copy;
            stk.pop();
            if(node->left != nullptr) {
                stk.push(node->left);
            }
            if(node->right != nullptr) {
                stk.push(node->right);
            }
        }
        stk.push(root);
        while(!stk.empty()) {
            Node * node = stk.top();
            stk.pop();
            if(node->left != nullptr) {
                nodes[node]->left = nodes[node->left];
                stk.push(node->left);
            }
            if(node->right != nullptr) {
                nodes[node]->right = nodes[node->right];
                stk.push(node->right);
            }
            if(node->random != nullptr) {
                nodes[node]->random = nodes[node->random];
            }
        }
        return nodes[root];
    }
};
