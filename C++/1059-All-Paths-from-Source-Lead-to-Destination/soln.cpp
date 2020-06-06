class Solution {
public:
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> graph(n);
        for(auto & e : edges) graph[e[0]].push_back(e[1]);
        vector<bool> visited(n, false);
        return dfs(source, destination, graph, visited);
        
    }
    
    bool dfs(int node, int destination, vector<vector<int>> & graph, vector<bool> visited) {
        if (graph[node].empty()) return node == destination;
        visited[node] = true;
        for(int nei : graph[node]) {
            if (visited[nei] || !dfs(nei, destination, graph, visited)) return false;
        }
        visited[node] = false;
        return true;
    }
};
