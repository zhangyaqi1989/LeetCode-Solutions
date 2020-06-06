class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        // Dijkstra's algorithm
        vector<vector<pair<int, int>>> graph(N + 1);
        for(const auto & time : times) {
            int u = time[0], v = time[1], w = time[2];
            graph[u].emplace_back(v, w);
        }
        vector<bool> processed(N + 1, false);
        priority_queue<pair<int, int>> frontier;
        frontier.push({0, K});
        vector<int> costs(N + 1, INT_MAX);
        costs[K] = 0;
        while (!frontier.empty()) {
            auto t = frontier.top();
            frontier.pop();
            int cost = -t.first, u = t.second;
            if (processed[u]) continue;
            processed[u] = true;
            for(auto & p : graph[u]) {
                int v = p.first, w = p.second;
                if (costs[v] > cost + w) {
                    costs[v] = cost + w;
                    frontier.push({-cost - w, v});
                }
            }
        }
        int mx = *max_element(costs.begin() + 1, costs.end());
        return mx == INT_MAX ? -1 : mx;
    }
};
