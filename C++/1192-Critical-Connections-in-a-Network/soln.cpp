class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        lows.assign(n, 1000000);
        ranks.assign(n, 1000000);
        visited.assign(n, 0);
        graph.resize(n);
        for(auto & edge : connections) {
            int u = edge[0], v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        time = 0;
        dfs(0, -1);
        vector<vector<int>> ans;
        // for(int i = 0; i < n; ++i) {
        //     cout << lows[i] << " ";
        // }
        // cout << endl;
        // for(int i = 0; i < n; ++i) {
        //     cout << ranks[i] << " ";
        // }
        // cout << endl;
        for(auto & edge : connections) {
            int u = edge[0], v = edge[1];
            if (lows[u] > ranks[v] || lows[v] > ranks[u]) ans.push_back(edge);
        }
        return ans;
    }
    
    void dfs(int node, int parent) {
        visited[node] = 1;
        ranks[node] = time;
        lows[node] = time;
        ++time;
        for(int nei : graph[node]) {
            if (!visited[nei]) {
                dfs(nei, node);
            }
        }
        for(int nei : graph[node]) {
            if (nei != parent) {
                lows[node] = min(lows[node], lows[nei]);
            }
        }
    }
    
private:
    vector<int> lows;
    vector<int> ranks;
    vector<vector<int>> graph;
    vector<int> visited;
    int time;
};
