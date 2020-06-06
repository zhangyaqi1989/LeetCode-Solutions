class Solution {
public:
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        for(auto & edge : edges) {
            int u = edge[0], v = edge[1];
            graph[u].push_back(v);
        }
        vector<bool> visited(n, false);
        return dfs(source, destination, visited);
    }
    
private:
    bool dfs(int node, int target, vector<bool> & visited) {
        if (graph.find(node) == graph.end()) return node == target;
        visited[node] = true;
        for (int nei : graph[node]) {
            if (visited[nei] || !dfs(nei, target, visited))
                return false;
        }
        visited[node] = false;
        return true;
    }
    unordered_map<int, vector<int>> graph;
};
