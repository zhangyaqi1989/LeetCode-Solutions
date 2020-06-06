class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int threshold) {
        vector<unordered_map<int, int>> graph(n);
        for(const auto & edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            graph[u].insert({v, w});
            graph[v].insert({u, w});
        }
        vector<int> connects(n);
        for(int i = 0; i < n; ++i) {
            connects[i] = Dijkstra(i, n, graph, threshold);
        }
        int ans = 0;
        for(int i = 0; i < n; ++i) {
            if (connects[i] <= connects[ans]) {
                ans = i;
            }
        }
        return ans;
    }
    
private:
    int Dijkstra(int start, int n, const vector<unordered_map<int, int>> & graph, int threshold) {
        unordered_map<int, int> costs;
        costs.insert({start, 0});
        priority_queue<pair<int, int>> frontier;
        frontier.push({0, start});
        vector<bool> processed(n, false);
        while (!frontier.empty()) {
            int cost, u;
            tie(cost, u) = frontier.top();
            frontier.pop();
            cost = -cost;
            if (processed[u]) continue;
            processed[u] = true;
            for(const auto & p : graph[u]) {
                int v = p.first, w = p.second;
                if (cost + w <= threshold && (costs.find(v) == costs.end() || costs[v] > w + cost)) {
                    costs[v] = w + cost;
                    frontier.push({- w - cost, v});
                } 
            }
        }
        return costs.size();
    }
};
