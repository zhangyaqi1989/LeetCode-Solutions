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
    vector<vector<int>> levelOrder(Node* root) {
        if (root == nullptr) return {};
        queue<Node *> front;
        front.push(root);
        vector<vector<int>> ans;
        while (!front.empty()) {
            int size = front.size();
            vector<int> level;
            for(int i = 0; i < size; ++i) {
                Node * node = front.front();
                front.pop();
                level.push_back(node->val);
                for(auto child : node->children)
                    front.push(child);
            }
            ans.push_back(level);
        }
        return ans;
    }
};
