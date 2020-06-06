/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
    Node* cloneGraph(Node* node) {
        // connected
        if (node == nullptr) return nullptr;
        unordered_map<Node *, Node *> nodes;
        stack<Node *> st;
        st.push(node);
        while (!st.empty()) {
            Node * u = st.top();
            st.pop();
            if (nodes.find(u) == nodes.end()) nodes[u] = new Node(u->val, {});
            Node * cu = nodes[u];
            for(Node * v : u->neighbors) {
                if (nodes.find(v) == nodes.end()) {
                    nodes[v] = new Node(v->val, {});
                    st.push(v);
                }
                cu->neighbors.push_back(nodes[v]);
            }
        }
        return nodes[node];
    }
};
