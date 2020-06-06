/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> vals;
        helper(root, vals);
        return vals;
    }
    
    void helper(Node * node, vector<int> & vals) {
        if (node != nullptr) {
            for(auto child : node->children) {
                helper(child, vals);
            }
            vals.push_back(node->val);
        }
    }
};