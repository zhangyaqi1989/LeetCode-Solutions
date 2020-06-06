/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int findClosestLeaf(TreeNode* root, int k) {
        // shortest distance on tree (treated as a undirected graph)
        vector<int> graph[1001];
        int leafs[1001] = {0};
        traverse(root, graph, leafs);
        queue<int> frontier;
        frontier.push(k);
        int visited[1001] = {0};
        visited[k] = 1;
        while (!frontier.empty()) {
            int node = frontier.front();
            if (leafs[node]) return node;
            frontier.pop();
            for(auto nei : graph[node]) {
                if (visited[nei] == 0){
                    visited[nei] = 1;
                    frontier.push(nei);
                }
            }
        }
        return 0;
        
    }
    
    void traverse(TreeNode * node, vector<int> graph[], int leafs[]) {
        if (node != nullptr) {
            if (node->left == nullptr && node->right == nullptr) {
                leafs[node->val] = 1;
            }
            if (node->left != nullptr) {
                graph[node->val].push_back(node->left->val);
                graph[node->left->val].push_back(node->val);
                traverse(node->left, graph, leafs);
            }
            if (node->right != nullptr) {
                graph[node->val].push_back(node->right->val);
                graph[node->right->val].push_back(node->val);
                traverse(node->right, graph, leafs);
            }
        }
    }
    
    
};
