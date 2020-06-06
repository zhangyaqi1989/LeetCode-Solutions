class Solution {
public:
    int treeDiameter(vector<vector<int>>& edges) {
        const int n = edges.size();
        vector<vector<int>> tree(n + 1);
        for(const auto & edge : edges) {
            int u = edge[0], v = edge[1];
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
        int deepest = 0, mx_depth = 0;
        dfs(0, -1, tree, 0, deepest, mx_depth);
        dfs(deepest, -1, tree, 0, deepest, mx_depth);
        return mx_depth;
    }
    
private:
    void dfs(int node, int parent, const vector<vector<int>> & tree, int depth, int & deepest, int & mx_depth) {
        if (depth > mx_depth) {
            mx_depth = depth;
            deepest = node;
        }
        for(int nei : tree[node]) {
            if (nei != parent) {
                dfs(nei, node, tree, depth + 1, deepest, mx_depth);
            }
        }
    }
};
