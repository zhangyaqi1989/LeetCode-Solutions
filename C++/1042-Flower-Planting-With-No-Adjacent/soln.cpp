class Solution {
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        vector<vector<int>> graph(N);
        vector<int> colors(N, -1);
        for(auto & path : paths) {
            int u = path[0], v = path[1];
            --u;
            --v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        for(int i = 0; i < N; ++i) {
            if (colors[i] == -1) {
                vector<int> used(5, false);
                for(int nei : graph[i]) {
                    if (colors[nei] != -1) used[colors[nei]] = true;
                }
                for(int c = 1; c < 5; ++c) {
                    if (!used[c]) {
                        colors[i] = c;
                        break;
                    }
                }
            }
        }
        return colors;
    }
};
