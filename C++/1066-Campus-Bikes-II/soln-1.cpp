class Solution {
public:
    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        // how to represent the state
        // update state
        const int nw = workers.size(), nb = bikes.size();
        priority_queue<pair<int, int>> frontier;
        frontier.push({0, 0});
        unordered_map<int, int> costs;
        costs[0] = 0;
        unordered_set<int> processed;
        while (!frontier.empty()) {
            auto t = frontier.top();
            int cost = -t.first, state = t.second;
            // cout << state << " " << cost << endl;
            frontier.pop();
            int idx = __builtin_popcount(state);
            if (idx == nw) return cost;
            if (processed.count(state)) continue;
            processed.insert(state);
            for(int j = 0; j < nb; ++j) {
                if (state & (1 << j)) continue;
                int new_state = state | (1 << j);
                int d = abs(workers[idx][0] - bikes[j][0]) + abs(workers[idx][1] - bikes[j][1]);
                auto it = costs.find(new_state);
                if (it == costs.end() || it->second > cost + d) {
                    costs[new_state] = cost + d;
                    frontier.push({-cost - d, new_state}); 
                }
            }
        }
        return -1;
    }
};
