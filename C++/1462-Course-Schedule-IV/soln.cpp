class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<bool>> graph(n, vector<bool>(n, false));
        for(int i = 0; i < n; ++i) graph[i][i] = true;
        for(const auto & e : prerequisites) {
            int u = e[0], v = e[1];
            graph[u][v] = true;
        }
        for(int k = 0; k < n; ++k) {
            for(int i = 0; i < n; ++i) {
                for(int j = 0; j < n; ++j) {
                    graph[i][j] = graph[i][j] | (graph[i][k] & graph[k][j]);
                }
            }
        }
        vector<bool> ans;
        for(const auto & q : queries) {
            ans.push_back(graph[q[0]][q[1]]);
        }
        return ans;
    }
};
