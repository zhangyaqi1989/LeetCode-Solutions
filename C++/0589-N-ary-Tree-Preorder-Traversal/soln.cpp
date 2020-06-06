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
    vector<int> preorder(Node* root) {
        if (root == NULL) return {};
        vector<int> ans;
        stack<Node *> s;
        s.push(root);
        Node * node;
        while (!s.empty())
        {
            node = s.top();
            ans.push_back(node->val);
            s.pop();
            for (int i = node->children.size() - 1; i >= 0; --i)
                s.push(node->children[i]);
        }
        return ans;
    }
};