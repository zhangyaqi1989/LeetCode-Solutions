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
public:

    // Encodes a tree to a single string.
    string serialize(Node* root) {
        string data;
        preorder(root, data);
        return data;
    }

    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        if(data.empty()) return nullptr;
        istringstream iss(data);
        string token;
        iss >> token;
        int val = stoi(token);
        Node * root = new Node(val, {});
        build(root, iss);
        return root;
    }
    
private:
    void build(Node * root, istringstream & iss) {
        string token;
        while(iss >> token) {
            if (token != "#") {
                root->children.push_back(new Node(stoi(token), {}));
                build(root->children.back(), iss);
            } else break;
        }
    }

    void preorder(Node * root, string & data) {
        if (root != nullptr) {
            if (!data.empty()) data += " ";
            data += to_string(root->val);
            for(Node * child : root->children)
                preorder(child, data);
            data += " #";
        }
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
