class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        const int n = quiet.size();
        vector<int> graph[n];
        for(auto & ab : richer) {
            int a = ab[0], b = ab[1];
            graph[b].push_back(a);
        }
        vector<int> ans;
        ans.resize(n);
        for(int i = 0; i < n; ++i) {
            ans[i] = i;
            dfs(graph, i, ans, quiet);
        }
        return ans;
        
    }
    
    void dfs(vector<int> graph[], int start, vector<int> & ans, vector<int>& quiet) {
        const int n = quiet.size();
        vector<bool> visited(n, false);
        stack<int> s;
        s.push(start);
        visited[start] = true;
        while (!s.empty()) {
            int node = s.top();
            s.pop();
            if (quiet[node] < quiet[ans[start]]) ans[start] = node;
            for(auto nei : graph[node]) {
                if (!visited[nei]) {
                    visited[nei] = true;
                    s.push(nei);
                }
            }
        }
        
    }
};
