class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        int target = (1 << n) - 1;
        queue<pair<int, int>> frontier;
        for(int i = 0; i < n; ++i) frontier.push({i, 1 << i});
        int step = 0;
        set<pair<int, int>> seen;
        while (!frontier.empty()) {
            int sz = frontier.size();
            int node, state;
            for(int i = 0; i < sz; ++i) {
                tie(node, state) = frontier.front();
                if (state == target) return step;
                frontier.pop();
                for(int nei : graph[node]) {
                    int new_state = state | (1 << nei);
                    if (seen.find({nei, new_state}) == seen.end()) {
                        seen.insert({nei, new_state});
                        frontier.push({nei, new_state});
                    }
                }
            }
            ++step;
        }
        return step;
    }
};
