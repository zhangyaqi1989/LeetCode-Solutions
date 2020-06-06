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
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if(root == nullptr) return ans;
        vector<Node *> frontier;
        frontier.push_back(root);
        while(!frontier.empty()) {
            vector<Node *> next_level;
            vector<int> level;
            for(Node * node : frontier) {
                level.push_back(node->val);
                for(Node * child : node->children) {
                    next_level.push_back(child);
                }
            }
            ans.push_back(level);
            swap(frontier, next_level);
        }
        return ans;
    }
};
