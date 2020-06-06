class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        vector<vector<int>> graph(n + 1);
        for(const auto & e : edges) {
            int u = e[0], v = e[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        double prob = 0.0;
        vector<bool> visited(n + 1, false);
        Dfs(graph, t, target, 1, 1.0, &prob, &visited);
        return prob;
    }
    
private:
    void Dfs(const vector<vector<int>> & graph, int t, int target, int node, double cur_prob, double * prob, vector<bool> * visited) {
        if (t < 0) return;
        if(t == 0 && node == target) {
            *prob += cur_prob;
        }
        (*visited)[node] = true;
        vector<int> cands;
        for(int nei : graph[node]) {
            if (!(*visited)[nei]) cands.push_back(nei);
        }
        if(cands.empty()) {
            if (t != 0 && node == target) *prob += cur_prob;
        } else {
            double new_prob = cur_prob / cands.size();
            for(int nei : cands) {
                Dfs(graph, t - 1, target, nei, new_prob, prob, visited);
            }
        }
        (*visited)[node] = false;
    }
};
