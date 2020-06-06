class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> children(n);
        for(int i = 0; i < n; ++i) {
            if (manager[i] != -1) children[manager[i]].push_back(i);
        }
        vector<int> frontier = {headID};
        int mx = 0;
        vector<int> costs(n, -1);
        costs[headID] = 0;
        while(!frontier.empty()) {
            vector<int> next_level;
            for(int u : frontier) {
                for(int v : children[u]) {
                    int new_cost = costs[u] + informTime[u];
                    if (costs[v] == -1 || costs[v] > new_cost) {
                        costs[v] = new_cost;
                        mx = max(mx, new_cost);
                        next_level.push_back(v);
                    }
                }
            }
            swap(next_level, frontier);
        }
        return mx;
    }
};
