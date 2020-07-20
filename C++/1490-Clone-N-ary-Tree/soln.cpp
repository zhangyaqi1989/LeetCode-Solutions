/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    Node* cloneTree(Node* root) {
        Node * new_root = nullptr;
        Dfs(root, nullptr, & new_root);
        return new_root;
    }
private:
    void Dfs(Node * node, Node * parent, Node ** new_root) {
        if(node != nullptr) {
            Node * new_node = new Node(node->val);
            if(parent != nullptr) {
                parent->children.push_back(new_node);
            } else {
                *new_root = new_node;
            }
            for(auto child : node->children) {
                Dfs(child, new_node, new_root);
            }
        }
    }
};
