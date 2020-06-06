/*
// Definition for a Node.
class Node {
public:
    int val = NULL;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Codec {
    
private:
    void preorder(Node * node, string & data) {
        if (node != nullptr) {
            data += " " + to_string(node->val);
            for(Node* child : node->children) {
                preorder(child, data);
            }
            data += " #";
        }
    }
    
    void build(Node * root, istringstream & iss) {
        string token;
        while (iss >> token) {
            if (token == "#") {
                break;
            }
            Node * child = new Node(stoi(token), {});
            root->children.push_back(child);
            build(child, iss);
        }
    }
    
public:

    // Encodes a tree to a single string.
    string serialize(Node* root) {
        string data = "";
        preorder(root, data);
        return data.empty() ? data : data.substr(1);
    }

    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        if (data.empty()) return nullptr;
        istringstream iss(data);
        string val;
        iss >> val;
        Node * root = new Node(stoi(val), {});
        build(root, iss);
        return root;
    }
    

};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
