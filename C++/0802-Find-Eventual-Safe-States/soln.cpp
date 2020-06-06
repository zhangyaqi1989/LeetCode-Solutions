class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        const int kN = graph.size();
        vector<int> memo(kN, -1);
        vector<bool> visited(kN, false);
        vector<int> ans;
        for(int i = 0; i < kN; ++i) {
            if(Dfs(graph, i, memo, visited)) ans.push_back(i);
        }
        return ans;
    }
    
private:
    bool Dfs(const vector<vector<int>>& graph, int u, vector<int> & memo, vector<bool> & visited) {
        if (memo[u] != -1) return memo[u];
        if (visited[u]) return false;
        visited[u] = true;
        bool ans = true;
        for(int v : graph[u]) {
            if (!Dfs(graph, v, memo, visited)) {
                ans = false;
                break;
            }
        }
        visited[u] = false;
        memo[u] = ans;
        return ans;
    }
};
