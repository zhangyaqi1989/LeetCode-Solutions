class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        // Dijkstra algorithm
        vector<vector<pair<int, int>>> graph(N + 1);
        for(const auto & e : times) {
            int u = e[0], v = e[1], w = e[2];
            graph[u].emplace_back(v, w);
        }
        priority_queue<pair<int, int>> pq;
        pq.push({0, K});
        vector<bool> processed(N + 1, false);
        vector<int> costs(N + 1, INT_MAX);
        costs[K] = 0;
        while(!pq.empty()) {
            int cost, u;
            tie(cost, u) = pq.top();
            pq.pop();
            cost = -cost;
            if (processed[u]) continue;
            processed[u] = true;
            for(const auto & e : graph[u]) {
                int v = e.first, w = e.second;
                if (costs[v] > cost + w) {
                    costs[v] = cost + w;
                    pq.push({-cost-w, v});
                }
            }
        }
        int ans = *max_element(costs.begin() + 1, costs.end());
        return ans == INT_MAX ? -1 : ans;
    }
};
