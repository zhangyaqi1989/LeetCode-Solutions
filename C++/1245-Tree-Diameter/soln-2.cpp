class Solution {
public:
    int treeDiameter(vector<vector<int>>& edges) {
        const int kN = edges.size() + 1;
        vector<vector<int>> tree(kN);
        for(const auto & edge : edges) {
            int u = edge[0], v = edge[1];
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
        int last = -1;
        int mx_depth = 0;
        dfs(tree, 0, -1, 0, &last, &mx_depth);
        mx_depth = 0;
        dfs(tree, last, -1, 0, &last, &mx_depth);
        return mx_depth;
    }
    
private:
    void dfs(const vector<vector<int>> & tree, int node, int parent, int depth, int * last, int * mx_depth) {
        if (depth > *mx_depth) {
            *mx_depth = depth;
            *last = node;
        }
        for(int nei : tree[node]) {
            if (parent != nei) {
                dfs(tree, nei, node, depth + 1, last, mx_depth);
            }
        }
    }

};
