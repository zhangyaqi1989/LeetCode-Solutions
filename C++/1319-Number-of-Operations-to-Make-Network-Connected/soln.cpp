class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int kCs = connections.size();
        if (kCs < n - 1) return -1;
        vector<vector<int>> graph(n);
        for(const auto & connect : connections) {
            int u = connect[0], v = connect[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        vector<bool> visited(n, false);
        int cnt = 0;
        for(int i = 0; i < n; ++i) {
            if (!visited[i]) {
                Dfs(graph, i, & visited);
                ++cnt;
            }
        }
        return cnt - 1;
    }
private:
    void Dfs(const vector<vector<int>> & graph, int u, vector<bool> * visited) {
        (*visited)[u] = true;
        for(int v : graph[u]) {
            if (!(*visited)[v]) Dfs(graph, v, visited);
        }
    }
};
