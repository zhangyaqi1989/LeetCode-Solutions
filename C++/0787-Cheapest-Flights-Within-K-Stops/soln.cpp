class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        // k = 0, 1
        // k = 1, 2
        vector<vector<pair<int, int>>> graph(n);
        for(const auto & flight : flights) {
            int u = flight[0], v = flight[1], w = flight[2];
            graph[u].emplace_back(v, w);
        }
        const int kInf = 10000000;
        int best = kInf;
        ++K;
        priority_queue<tuple<int, int, int>> frontier;
        frontier.push({0, 0, src});
        while (!frontier.empty()) {
            int cost, len, u;
            tie(cost, len, u) = frontier.top();
            frontier.pop();
            cost = -cost;
            if (u == dst) {
                return cost;
            }
            if (len + 1 > K) continue;
            for(auto & p : graph[u]) {
                int v, w;
                tie(v, w) = p;
                frontier.push({-cost-w, len + 1, v});
            }
        }
        return -1;
    }
};
