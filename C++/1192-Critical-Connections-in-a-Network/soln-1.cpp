class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> graph(n);
        for(const auto & connection : connections) {
            int u = connection[0], v = connection[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        vector<int> starts(n, -1);
        vector<int> lows(n);
        int timer = 0;
        Dfs(0, -1, graph, &starts, &lows, &timer);
        vector<vector<int>> ans;
        for(const auto & connection : connections) {
            int u = connection[0], v = connection[1];
            if (lows[v] > starts[u] || lows[u] > starts[v]) {
                ans.push_back(connection);
            }
        }
        return ans;
    }
    
private:
    void Dfs(int node, int parent, const vector<vector<int>> & graph, vector<int> * starts, vector<int> * lows, int * timer) {
        (*starts)[node] = (*timer);
        (*lows)[node] = (*starts)[node];
        *timer += 1;
        for(int nei : graph[node]) {
            if ((*starts)[nei] == -1) {
                Dfs(nei, node, graph, starts, lows, timer);
            }
            if (nei != parent) {
                (*lows)[node] = min((*lows)[node], (*lows)[nei]);
            }
        }

    }
};
