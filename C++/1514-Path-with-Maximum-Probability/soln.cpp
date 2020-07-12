class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int, double>>> graph(n);
        for(size_t i = 0; i < edges.size(); ++i) {
            int u = edges[i][0], v = edges[i][1];
            double p = succProb[i];
            graph[u].emplace_back(v, p);
            graph[v].emplace_back(u, p);
        }
        priority_queue<pair<double, int>> frontier;
        frontier.push({1.0, start});
        vector<double> probs(n, 0.0);
        probs[start] = 1.0;
        vector<bool> processed(n, false);
        while(!frontier.empty()) {
            auto [prob, u] = frontier.top();
            frontier.pop();
            if(u == end) return prob;
            if(processed[u]) continue;
            processed[u] = true;
            for(const auto & vw : graph[u]) {
                auto [v, w] = vw;
                double new_prob = prob * w;
                if(probs[v] < new_prob) {
                    probs[v] = new_prob;
                    frontier.push({new_prob, v});
                }
            }
        }
        return 0.0;
    }
};
